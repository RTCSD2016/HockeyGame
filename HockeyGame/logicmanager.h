#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

namespace Hockey
{
    typedef struct _Point
    {
        int x;
        int y;
    }Point;

    class LogicManager
    {
    public:

        LogicManager();

        void  Run();

        void  SetVelocity(float v_x, float v_y);//get velocity and direction of ball

        void  SetPosition(float x,float y);          //get position of ball

        void  SetRobotPosition(float x,float y);

        float GetTime();     //moving time of robot

        void  TargetVector();//direction of robot at the targer point

        Point Gettarget();

    private:

        Point target;

        float Velocity;
        float Velocity_x;
        float Velocity_y;

        float Ball_x;
        float Ball_y;
        float Ball_radius;

        float Robot_x;
        float Robot_y;
        float Robot_radius;

        float Target_x;
        float Target_y;

        float Time;

    };


}

#endif // LOGICMANAGER_H
