#include "MotionControl.h"

motion_control::motion_control(int i)
{
	CurrentPosition.Position[0] = 0;
	CurrentPosition.Position[1] = 0;
	CurrentPosition.Velocity[0] = 0;
	CurrentPosition.Velocity[1] = 0;
	Status = Idel;
}

motionControlStatusDef motion_control::GetStatus(void)
{
	return Status;
}

void motion_control::SetCurrentPosition(float x, float y)
{
    CurrentPosition.Position[0] = x;
    CurrentPosition.Position[1] = y;
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



