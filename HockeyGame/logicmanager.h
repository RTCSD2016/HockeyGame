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

        void Run();

        void SetVelocity(int v,int v_x,int v_y);//get velocity and direction of ball

        void SetPosition(int x,int y);          //get position of ball

        void GetTarget();   //impact point

        void GetTime();     //moving time of robot

        void TargetVector();//direction of robot at the targer point

        Point Gettarget();

    private:

        Point target;

        int Velocity;
        int Velocity_x;
        int Velocity_y;

        int Ball_x;
        int Ball_y;
        int Ball_radius;

        int Robot_x;
        int Robot_y;
        int Robot_radius;

        int Target_x;
        int Target_y;

        float Time;

    };


}

#endif // LOGICMANAGER_H
