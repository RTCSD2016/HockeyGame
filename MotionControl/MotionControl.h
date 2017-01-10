#ifndef __MOTIONCONTROL_H
#define __MOTIONCONTROL_H

#ifdef __cplusplus
extern "C" { 
#endif

#include <native/timer.h>

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

//Global variables
extern RT_QUEUE MotionCmdMassage;

#ifdef __cplusplus 
}
#endif
#endif