#ifndef MESSAGETYPES_H
#define MESSAGETYPES_H

#define red_robot_set_target                1
#define green_robot_set_target              2
#define red_robot_get_velocity              3
#define green_robot_get_velocity            4
#define controler_need_red_robot_target     5
#define controler_need_green_robot_target   6

typedef struct _Velocity
{
    float vx;
    float vy;
}Velocity;

#endif // MESSAGETYPES_H
