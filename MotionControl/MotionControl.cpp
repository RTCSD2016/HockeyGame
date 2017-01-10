#include <stdio.h>
#include <math.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>

#include <native/task.h>
#include <native/timer.h>
#include <native/queue.h>

#include <MotionControl.h>

// Data Type
typedef struct
{
    double Position[2];
    double Velocity[2];
} AxisPosition;

//Global variables
RT_TASK task_command_sender;
RT_TASK task_motion_control;

RT_QUEUE MotionCmdMassage;

/*****************************************************
 * status machine
 * 
*****************************************************/
typedef enum
{
	Idel = 0,
	Cal
}motionControlStatusDef;

//class
class motion_control
{
private:
	AxisPosition CurrentPosition;
	AxisPosition StartPosition;
	RTIME StartTime;
	motionControlStatusDef Status;
	MotionCmd recivedCmd;

	double vm_x, vm_y, v0_x, v_x, v0_y, v_y, s_x, s_y, t, t1_x, t2_x, t1_y, t2_y;
public:
	motion_control(int i);
	motionControlStatusDef GetStatus(void);
	void GetNewPosition(RT_QUEUE * CmdMassage, AxisPosition * Position);
	
};

motion_control::motion_control(int i)
{
	CurrentPosition.Position[0] = 0;
	CurrentPosition.Position[1] = 0;
	CurrentPosition.Velocity[0] = 0;
	CurrentPosition.Velocity[1] = 0;
	Status = Idel;
//	printf("x:%lf\ty:%lf\tvx:%lf\tvy:%lf\n", CurrentPosition.Position[0],CurrentPosition.Position[1],CurrentPosition.Velocity[0], CurrentPosition.Velocity[1]);
}

motionControlStatusDef motion_control::GetStatus(void)
{
	return Status;
}

void motion_control::GetNewPosition(RT_QUEUE * CmdMassage, AxisPosition * Position)
{
	size_t massageSize;
	double delta_t;
	switch(Status)
	{
	case Idel:
		massageSize = rt_queue_read(CmdMassage, &recivedCmd, sizeof(recivedCmd), TM_INFINITE);
		StartTime = rt_timer_read();
		StartPosition = CurrentPosition;

		t = (double)(recivedCmd.time - StartTime) / 1000000000;
		//x
		s_x  = recivedCmd.Position[0] - StartPosition.Position[0];
		v0_x = StartPosition.Velocity[0];
		v_x  = recivedCmd.Velocity[0];
		vm_x = s_x / t;
		if(v0_x > vm_x && vm_x > v_x)
			vm_x = 0.5 * (2.0*Acceleration*s_x+v_x*v_x-v0_x*v0_x) / (Acceleration*t+v_x-v0_x);
		else if(v0_x < vm_x && vm_x < v_x)
			vm_x = 0.5 * (2.0*Acceleration*s_x-v_x*v_x+v0_x*v0_x) / (Acceleration*t-v_x+v0_x);
		else if(v0_x < vm_x && vm_x > v_x)
			vm_x = 0.5*(Acceleration*t+v_x+v0_x) - (0.5*Acceleration)*sqrt((t+(v_x+v0_x)/Acceleration)*(t+(v_x+v0_x)/Acceleration) - (4.0/Acceleration)*(0.5*(v_x*v_x+v0_x*v0_x)/Acceleration + s_x));
		else
			vm_x = 0.5*(-Acceleration*t+v_x+v0_x) + (0.5*Acceleration)*sqrt((t-(v_x+v0_x)/Acceleration)*(t-(v_x+v0_x)/Acceleration) - (4.0/Acceleration)*(0.5*(v_x*v_x+v0_x*v0_x)/Acceleration -s_x));
		t1_x = fabs(vm_x - v0_x) / Acceleration;
		t2_x = t - fabs(vm_x - v_x) / Acceleration;
		//y
		s_y  = recivedCmd.Position[1] - StartPosition.Position[1];
		v0_y = StartPosition.Velocity[1];
		v_y  = recivedCmd.Velocity[1];
		vm_y = s_y / t;
		if(v0_y > vm_y && vm_y > v_y)
			vm_y = 0.5 * (2.0*Acceleration*s_y+v_y*v_y-v0_y*v0_y) / (Acceleration*t+v_y-v0_y);
		else if(v0_y < vm_y && vm_y < v_y)
			vm_y = 0.5 * (2.0*Acceleration*s_y-v_y*v_y+v0_y*v0_y) / (Acceleration*t-v_y+v0_y);
		else if(v0_y < vm_y && vm_y > v_y)
			vm_y = 0.5*(Acceleration*t+v_y+v0_y) - (0.5*Acceleration)
				*sqrt((t+(v_y+v0_y)/Acceleration)*(t+(v_y+v0_y)/Acceleration) - (4.0/Acceleration)*(0.5*(v_y*v_y+v0_y*v0_y)/Acceleration + s_y));
		else
			vm_y = 0.5*(-Acceleration*t+v_y+v0_y) + (0.5*Acceleration)
				*sqrt((t-(v_y+v0_y)/Acceleration)*(t-(v_y+v0_y)/Acceleration) - (4.0/Acceleration)*(0.5*(v_y*v_y+v0_y*v0_x)/Acceleration -s_y));
		t1_y = fabs(vm_y - v0_y) / Acceleration;
		t2_y = t - fabs(vm_y - v_y) / Acceleration;
		Status = Cal;
	case Cal:
		delta_t = (double)(rt_timer_read() - StartTime) / 1000000000;
		//x axis
		if(delta_t < t1_x)
		{
			CurrentPosition.Velocity[0] = v0_x + (vm_x>v0_x ? Acceleration:-Acceleration)*delta_t;
			CurrentPosition.Position[0] = StartPosition.Position[0] + v0_x*delta_t + 0.5*(vm_x>v0_x ? Acceleration:-Acceleration)*delta_t*delta_t;
		}
		else if(delta_t < t2_x)
		{
			CurrentPosition.Velocity[0] = vm_x;
			CurrentPosition.Position[0] = StartPosition.Position[0] + v0_x*t1_x + 0.5*(vm_x>v0_x ? Acceleration:-Acceleration)*t1_x*t1_x + vm_x*(delta_t-t1_x);
		}
		else
		{
			CurrentPosition.Velocity[0] = vm_x + (vm_x<v_x ? Acceleration:-Acceleration)*(delta_t-t2_x);
			CurrentPosition.Position[0] = StartPosition.Position[0] + v0_x*t1_x + 0.5*(vm_x>v0_x ? Acceleration:-Acceleration)*t1_x*t1_x + vm_x*(t2_x-t1_x) + vm_x*(delta_t-t2_x) + 0.5*(vm_x<v_x ? Acceleration:-Acceleration)*(delta_t-t2_x)*(delta_t-t2_x);
		}
		//y axis
		if(delta_t < t1_y)
		{
			CurrentPosition.Velocity[1] = v0_y + (vm_y>v0_y ? Acceleration:-Acceleration)*delta_t;
			CurrentPosition.Position[1] = StartPosition.Position[1] + v0_y*delta_t + 0.5*(vm_y>v0_y ? Acceleration:-Acceleration)*delta_t*delta_t;
		}
		else if(delta_t < t2_y)
		{
			CurrentPosition.Velocity[1] = vm_y;
			CurrentPosition.Position[1] = StartPosition.Position[1] + v0_y*t1_y + 0.5*(vm_y>v0_y ? Acceleration:-Acceleration)*t1_y*t1_y + vm_y*(delta_t-t1_y);
		}
		else
		{
			CurrentPosition.Velocity[1] = vm_y + (vm_y<v_y ? Acceleration:-Acceleration)*(delta_t-t2_y);
			CurrentPosition.Position[1] = StartPosition.Position[1] + v0_y*t1_y + 0.5*(vm_y>v0_y ? Acceleration:-Acceleration)*t1_y*t1_y + vm_y*(t2_y-t1_y) + vm_y*(delta_t-t2_y) + 0.5*(vm_y<v_y ? Acceleration:-Acceleration)*(delta_t-t2_y)*(delta_t-t2_y);
		}
		if(delta_t > t)
		{
//			CurrentPosition.Velocity[0] = v_x;
//			CurrentPosition.Velocity[1] = v_y;
			Status = Idel;
		}
		break;
	}
	*Position = CurrentPosition;
}

void task_motion_control_proc(void *arg)
{
	RTIME now, previous;
	MotionCmd recivedCmd;
	size_t massageSize;
	AxisPosition Position;

	//creat Massage Queue
	rt_queue_create(&MotionCmdMassage, (const char *)"MotionCmdMassage", sizeof(MotionCmd)*MessageQueue_Size, sizeof(MotionCmd), Q_FIFO);
	
	/*
	 * Arguments: &task (NULL=self),
	 *            start time,
	 *            period (here: 1 s)
	 */
	rt_task_set_periodic(NULL, TM_NOW, 1000000000);
	previous = rt_timer_read();

	motion_control motion_control_xy(1);

	int temp;

	float delta_T;
	while (1) {
		rt_task_wait_period(NULL);
		motion_control_xy.GetNewPosition(&MotionCmdMassage, &Position);
		printf("vx:%lf\tvy:%lf\tx:%lf\ty:%lf\tT:%lf\n",Position.Velocity[0],Position.Velocity[1],Position.Position[0],Position.Position[1], (double)rt_timer_read()/1000000000);
	}
}

void task_command_sender_proc(void *arg)
{
	RTIME now, previous;
	int cycle_count;
	MotionCmd sendCmd;

	/*
	 * Arguments: &task (NULL=self),
	 *            start time,
	 *            period (here: 2 s)
	 */
	rt_task_set_periodic(NULL, TM_NOW, 2000000000);
	previous = rt_timer_read();

	cycle_count = 0;
now = rt_timer_read();	
		sendCmd.Position[0] = -100;
		sendCmd.Position[1] = -100;
		sendCmd.Velocity[0] = -15;
		sendCmd.Velocity[1] = -15;
		sendCmd.time = now + rt_timer_ns2ticks((long)10*1000000000);
		rt_queue_write(&MotionCmdMassage, &sendCmd, sizeof(sendCmd), Q_NORMAL);
	printf("%lf\tTime to:%lf\n", (double)now/1000000000 ,(double)sendCmd.time / 1000000000);
	while (1) {
		rt_task_wait_period(NULL);
		now = rt_timer_read();

		previous = now;
		cycle_count = cycle_count + 1;
		printf("cycle_count:%d\n",cycle_count);


	}
}

void catch_signal(int sig)
{

}


int main(int argc, char* argv[])
{
	signal(SIGTERM, catch_signal);
	signal(SIGINT, catch_signal);

	/* Avoids memory swapping for this program */
	mlockall(MCL_CURRENT|MCL_FUTURE);

    printf("A simple motion control demo\n");



	/*
	 * Arguments: &task,
	 *            name,
	 *            stack size (0=default),
	 *            priority,
	 *            mode (FPU, start suspended, ...)
	 */
	rt_task_create(&task_motion_control, "rttask_motion_control", 0, 99, 0);
	rt_task_create(&task_command_sender, "rttask_command_sender", 0, 98, 0);

	/*
	 * Arguments: &task,
	 *            task function,
	 *            function argument
	 */
	rt_task_start(&task_motion_control, &task_motion_control_proc, NULL);
	rt_task_start(&task_command_sender, &task_command_sender_proc, NULL);

    while(1);
    printf("End! \n");
		
	rt_task_delete(&task_motion_control);
	rt_task_delete(&task_command_sender);
	return 0;
}


