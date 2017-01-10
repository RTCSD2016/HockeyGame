#ifndef __MOTIONCONTROL_H
#define __MOTIONCONTROL_H

#ifdef __cplusplus
extern "C" { 
#endif

#include <math.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>

#include <native/timer.h>
#include <native/task.h>
#include <native/timer.h>
#include <native/queue.h>

// Data Type
typedef struct
{
    double Position[2];
    double Velocity[2];
    RTIME  time;
} MotionCmd;

// Parameter
#define Acceleration		10		// m*s^-2
#define X_AxisPosition_Min	0		// m
#define X_AxisPosition_Max	1		// m
#define Y_AxisPosition_Min	0		// m
#define Y_AxisPosition_Max	1		// m

#define MessageQueue_Size	10

// Data Type
typedef struct
{
    double Position[2];
    double Velocity[2];
} AxisPosition;

/*****************************************************
 * status machine
 *
*****************************************************/
typedef enum
{
    Idel = 0,
    Cal
}motionControlStatusDef;

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
    void SetCurrentPosition(float x,float y);

};

#ifdef __cplusplus 
}
#endif
#endif
