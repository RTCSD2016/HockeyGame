#include "runthread.h"
#include "gameobjects.h"
#include "collision.h"
#include <QTime>

namespace Hockey
{
    RunThread::RunThread(){

    }

    void RunThread::run(){
        while(true){

            if(Ball::GetInstance()->getY()<0||Ball::GetInstance()->getY()>500)
            {
                if(Ball::GetInstance()->getY()<0)
                {
                    int point = RedRobot::GetInstance()->GetPoint();

                    RedRobot::GetInstance()->SetPoint(++point);
                    point = RedRobot::GetInstance()->GetPoint();
                }
                else
                {
                    int point = GreenRobot::GetInstance()->GetPoint();

                    GreenRobot::GetInstance()->SetPoint(++point);
                    point = GreenRobot::GetInstance()->GetPoint();

                }

                QTime time;
                time= QTime::currentTime();
                qsrand(time.msec()+time.second()*1000);

                float vx = qrand()%18-10;
                float vy = qrand()%18-10;

                Ball::GetInstance()->SetPosition(150,250);
                Ball::GetInstance()->setVelocity(vx,vy);
            }
//            qDebug()<<Ball::GetInstance()->getVelocity_y();
            Ball::GetInstance()->Move_x(Ball::GetInstance()->getVelocity_x());
            Ball::GetInstance()->Move_y(Ball::GetInstance()->getVelocity_y());
            //RedRobot::GetInstance()->Move_x();
            //RedRobot::GetInstance()->Move_y();
            //GreenRobot::GetInstance()->Move_x();
            //GreenRobot::GetInstance()->Move_y();
            msleep(20);
            int check = Collision::getInstance()->checkCls();
            switch (check)
            {
            case 0:
                break;
            case 1:
                Collision::getInstance()->bounce_sides();
                //qDebug()<<"collided with sides!";
                break;
            case 2:
                Collision::getInstance()->bounce_tb();
                //qDebug()<<"collided with tb!";
                break;
            case 3:
                Collision::getInstance()->col_RR();
                //qDebug()<<"collided with redrobot!";
                break;
            case 4:
                Collision::getInstance()->col_GR();
                //qDebug()<<"collided with greenrobot!";
                break;
            }
        }
    }
}
