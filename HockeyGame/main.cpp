#include <QApplication>
#include <QSurfaceFormat>
#include "guimain.h"
#include "MotionControl.h"
#include "messagetypes.h"

using namespace Hockey;

//Global variables
RT_TASK redrobot_task_command_sender;
RT_TASK redrobot_task_motion_control;
RT_TASK greenrobot_task_command_sender;
RT_TASK greenrobot_task_motion_control;
RT_QUEUE MotionCmdMassage;

void redrobot_task_motion_control_proc(void *arg)
{
    AxisPosition Position;

    //creat Message Queue
    rt_queue_create(&MotionCmdMassage, (const char *)"MotionCmdMassage", sizeof(MotionCmd)*MessageQueue_Size, sizeof(MotionCmd), Q_FIFO);

    /*
     * Arguments: &task (NULL=self),
     *            start time,
     *            period (here: 1 s)
     */
    rt_task_set_periodic(NULL, TM_NOW, 1000000000);

    motion_control motion_control_xy(1);

    motion_control_xy.SetCurrentPosition(RedRobot::GetInstance()->getX(),
                                         RedRobot::GetInstance()->getY());

    while (1) {
        rt_task_wait_period(NULL);
        motion_control_xy.GetNewPosition(&MotionCmdMassage, &Position);
        Velocity v;
        v.vx = Position.Velocity[0];
        v.vy = Position.Velocity[1];
        Message msg;
        msg.type = red_robot_get_velocity;
        msg.message = &v;
        Messenger::GetInstance()->PostMessage(msg);
    }
}

void redrobot_task_command_sender_proc(void *arg)
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

    sendCmd.Position[0] = 100;
    sendCmd.Position[1] = 100;
    sendCmd.Velocity[0] = 15;
    sendCmd.Velocity[1] = 15;

    while (1) {
        rt_task_wait_period(NULL);
        now = rt_timer_read();

        Message needtarget;

        needtarget.type = controler_need_red_robot_target;
        Messenger::GetInstance()->PostMessage(needtarget);

        Message msg = Messenger::GetInstance()->ReceiveMessage(red_robot_set_target);

        if(msg.type==red_robot_set_target)
        {
            Point position = *(Point*)msg.message;
            sendCmd.Position[0] = position.x;
            sendCmd.Position[1] = position.y;
            sendCmd.Velocity[0] = -15;
            sendCmd.Velocity[1] = -15;
        }

        sendCmd.time = now + rt_timer_ns2ticks((long)10*1000000000);

        rt_queue_write(&MotionCmdMassage, &sendCmd, sizeof(sendCmd), Q_NORMAL);

        previous = now;
        cycle_count = cycle_count + 1;
    }
}

void greenrobot_task_motion_control_proc(void *arg)
{
    AxisPosition Position;

    //creat Massage Queue
    rt_queue_create(&MotionCmdMassage, (const char *)"MotionCmdMassage", sizeof(MotionCmd)*MessageQueue_Size, sizeof(MotionCmd), Q_FIFO);

    /*
     * Arguments: &task (NULL=self),
     *            start time,
     *            period (here: 1 s)
     */
    rt_task_set_periodic(NULL, TM_NOW, 1000000000);

    motion_control motion_control_xy(1);

    motion_control_xy.SetCurrentPosition(GreenRobot::GetInstance()->getX(),
                                         GreenRobot::GetInstance()->getY());

    while (1) {
        rt_task_wait_period(NULL);
        motion_control_xy.GetNewPosition(&MotionCmdMassage, &Position);
    }
}

void greenrobot_task_command_sender_proc(void *arg)
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

    while (1) {
        rt_task_wait_period(NULL);
        now = rt_timer_read();

        Message msg = Messenger::GetInstance()->ReceiveMessage(green_robot_set_target);

        if(msg.type==green_robot_set_target)
        {
            Point position = *(Point*)msg.message;
            sendCmd.Position[0] = position.x;
            sendCmd.Position[1] = position.y;
            sendCmd.Velocity[0] = -15;
            sendCmd.Velocity[1] = -15;
        }

        sendCmd.time = now + rt_timer_ns2ticks((long)10*1000000000);

        rt_queue_write(&MotionCmdMassage, &sendCmd, sizeof(sendCmd), Q_NORMAL);

        previous = now;
        cycle_count = cycle_count + 1;
    }
}

void catch_signal(int sig)
{

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setSamples(4);
    QSurfaceFormat::setDefaultFormat(format);

    GuiMain gui;
    gui.show();

    signal(SIGTERM, catch_signal);
    signal(SIGINT, catch_signal);

    mlockall(MCL_CURRENT|MCL_FUTURE);

    rt_task_create(&redrobot_task_motion_control, "redrobot_rttask_motion_control", 0, 99, 0);
    rt_task_create(&redrobot_task_command_sender, "redrobot_rttask_command_sender", 0, 98, 0);
    rt_task_create(&greenrobot_task_motion_control, "greenrobot_rttask_motion_control", 0, 97, 0);
    rt_task_create(&greenrobot_task_command_sender, "greenrobot_rttask_command_sender", 0, 96, 0);

    rt_task_start(&redrobot_task_motion_control, &redrobot_task_motion_control_proc, NULL);
    rt_task_start(&redrobot_task_command_sender, &redrobot_task_command_sender_proc, NULL);
    rt_task_start(&greenrobot_task_motion_control, &greenrobot_task_motion_control_proc, NULL);
    rt_task_start(&greenrobot_task_command_sender, &greenrobot_task_command_sender_proc, NULL);

    return a.exec();
}
