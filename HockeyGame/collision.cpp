#include "collision.h"

namespace Hockey
{
    Collision::Collision(){

    }

    Collision* Collision::col = nullptr;

    Collision* Collision::getInstance()
    {
        if(col == nullptr)
        {
            col=new Collision();
        }
        return col;
    }

    int Collision::checkCls(){
        float distance_br = sqrt(pow(ball->getX() + ball->getR()- RedRobot::GetInstance()->getX() - RedRobot::GetInstance()->getR(), 2) +
                                  pow(ball->getY() + ball->getR()- RedRobot::GetInstance()->getY() - RedRobot::GetInstance()->getR(),2));
        float distance_bg = sqrt(pow(ball->getX() + ball->getR() - GreenRobot::GetInstance()->getX() - GreenRobot::GetInstance()->getR(), 2) +
                                  pow(ball->getY() + ball->getR() - GreenRobot::GetInstance()->getY() - GreenRobot::GetInstance()->getR(),2));

        //collision with the Arena's sides
        if (ball->getX() >= 265 || ball->getX() <= 20 ){
            return 1;
        }
        //collision with the Arena's top or bottom
        if ((ball->getY() <= 40 || ball->getY() >= 435) &&
                (ball->getX() <= 100 || ball->getX() >= 190)){
            return 2;
        }
        //collision with the RedRobot
        else if (distance_br <= ball->getR() + RedRobot::GetInstance()->getR())
        {
            return 3;
        }
        //collision with the GreenRobot
        else if (distance_bg <= ball->getR() + GreenRobot::GetInstance()->getR())
        {
            return 4;
        }
        //no collision occurs
        else return 0;
    }

    void Collision::bounce_sides(){
        ball->setVelocity(-ball->getVelocity_x(), ball->getVelocity_y());
    }

    void Collision::bounce_tb(){
        ball->setVelocity(ball->getVelocity_x(), -ball->getVelocity_y());
    }

    void Collision::col_RR(){
        float alp;
        if (RedRobot::GetInstance()->getX() + RedRobot::GetInstance()->getR() - ball->getX() - ball->getR() != 0){
            alp = atan((ball->getY() + ball->getR() - RedRobot::GetInstance()->getY() - RedRobot::GetInstance()->getR()) /
                       (RedRobot::GetInstance()->getX() + RedRobot::GetInstance()->getR() - ball->getX() - ball->getR()));     //Buggy!
//            qDebug()<<alp;
            float vx_new = ball->getVelocity_x() * (pow(sin(alp), 2) - pow(cos(alp), 2)) + 2 * ball->getVelocity_y() * sin(alp) * cos (alp);
            float vy_new = ball->getVelocity_y() * (pow(cos(alp), 2) - pow (sin(alp), 2)) -2 * ball->getVelocity_x() * sin(alp) * cos(alp);
            qDebug()<<vy_new;
            ball->setVelocity(vx_new, vy_new);
        }else{
            ball->setVelocity(ball->getVelocity_x(), -ball->getVelocity_y());
        }
    }

    void Collision::col_GR(){
        float alp;
        if (RedRobot::GetInstance()->getX() + RedRobot::GetInstance()->getR() - ball->getX() - ball->getR() != 0){
            alp = atan((ball->getY() + ball->getR() - RedRobot::GetInstance()->getY() - RedRobot::GetInstance()->getR()) /
                       (RedRobot::GetInstance()->getX() + RedRobot::GetInstance()->getR() - ball->getX() - ball->getR()));     //Buggy!
//            qDebug()<<alp;
            float vx_new = ball->getVelocity_x() * (pow(sin(alp), 2) - pow(cos(alp), 2)) + 2 * ball->getVelocity_y() * sin(alp) * cos (alp);
            float vy_new = ball->getVelocity_y() * (pow(cos(alp), 2) - pow (sin(alp), 2)) -2 * ball->getVelocity_x() * sin(alp) * cos(alp);
            qDebug()<<vy_new;
            ball->setVelocity(vx_new, vy_new);
        }else{
            ball->setVelocity(ball->getVelocity_x(), -ball->getVelocity_y());
        }
    }
}
