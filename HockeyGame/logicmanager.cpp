#include "logicmanager.h"
#include <stdlib.h>
#include <cmath>
namespace Hockey 
{
    float B_x;
    float B_y;
    float step_x;
    float step_y;

    LogicManager::LogicManager()
    {

    }

    void LogicManager::SetVelocity(float v_x, float v_y)
    {
        Velocity_x = v_x;
        Velocity_y = v_y;
    }

    void LogicManager::SetPosition(float x,float y)
    {
        Ball_x = x;
        Ball_y = y;

    }

    void LogicManager::SetRobotPosition(float x, float y)
    {
        Robot_x = x;
        Robot_y = y;
    }

    /*float LogicManager::GetTime()
    {
        float distance = sqrt((B_x-Ball_x)*(B_x-Ball_x)+(B_y-Ball_y)*(B_y-Ball_y));
        Time = distance/Velocity;
        return Time;
    }*/

    void LogicManager::TargetVector()
    {
       float x = 90+rand()%120;                      //gate position_x
       float k_v2 = B_y/(x-B_x) ;                   //Ball reflet direction
       float k_v1 = Velocity_y/Velocity_x;          //Ball direction
       float k = tan((atan(k_v2)+atan(k_v1))/2);    //Robot direction
       step_x = cos(atan(k));
       step_y = sin(atan(k));
    }

    void LogicManager::Run()
    {
        B_x = (Robot_y-Ball_y+Robot_x*Velocity_x/Velocity_y+Ball_x*Velocity_y/Velocity_x)/(Velocity_x/Velocity_y+Velocity_y/Velocity_x);
        B_y = Velocity_y/Velocity_x*(Target_x-Ball_x)+Ball_y;
        Target_x = B_x+step_x*(Ball_radius+Robot_radius);
        Target_y = B_y+step_y*(Ball_radius+Robot_radius);
    }

   Point LogicManager::Gettarget()
   {

        target.x=Target_x;
        target.y=Target_y;
        return target;
   }
}
