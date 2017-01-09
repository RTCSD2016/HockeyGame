#include "runthread.h"
#include "gameobjects.h"
#include "collision.h"

namespace Hockey
{
    RunThread::RunThread(){

    }

    void RunThread::run(){
        while(true){
//            qDebug()<<Ball::GetInstance()->getVelocity_y();
            Ball::GetInstance()->Move_x(Ball::GetInstance()->getVelocity_x());
            Ball::GetInstance()->Move_y(Ball::GetInstance()->getVelocity_y());
            msleep(20);
            int check = Collision::getInstance()->checkCls();
            switch (check)
            {
            case 0:
                break;
            case 1:
                Collision::getInstance()->bounce_sides();
                qDebug()<<"collided with sides!";
                break;
            case 2:
                Collision::getInstance()->bounce_tb();
                qDebug()<<"collided with tb!";
                break;
            case 3:
                Collision::getInstance()->col_RR();
                qDebug()<<"collided with redrobot!";
                break;
            case 4:
                Collision::getInstance()->col_GR();
                qDebug()<<"collided with greenrobot!";
                break;
            }
        }
    }
}
