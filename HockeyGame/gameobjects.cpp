#include "gameobjects.h"

namespace Hockey
{
    RedRobot* RedRobot::pInstance = NULL;

    RedRobot* RedRobot::GetInstance()
    {
        if(pInstance == NULL)
        {
            pInstance=new RedRobot();
        }
        return pInstance;
    }

    void RedRobot::Initialize()
    {
        QPixmap pixmap(":/picture/resource/red.png");
        diameter = pixmap.height();
        pos_x = 150;
        pos_y = 60;
        point = 0;
        pixmap.scaled(diameter,diameter,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        texture.setTexture(pixmap);
        edge.setColor(QColor(255,0,255));
        edge.setWidth(1);

        logic = new LogicManager();

        velocity.vx = 0;
        velocity.vy = 0;

        connect(Messenger::GetInstance(),
                   SIGNAL(sig_newMessageIn(int)),
                   this,
                   SLOT(Update(int)));
    }

    void RedRobot::Draw(QPainter *painter)
    {
        painter->save();
        painter->translate(pos_x,pos_y);
        painter->setBrush(texture);
        painter->setPen(edge);
        painter->drawEllipse(0,0,diameter,diameter);
        painter->restore();
    }

    void RedRobot::Update(int messagetype)
    {
        Message msg = Messenger::GetInstance()->ReceiveMessage(controler_need_red_robot_target);

        if(msg.type==controler_need_red_robot_target)
        {
            logic->SetPosition(Ball::GetInstance()->getX(),Ball::GetInstance()->getY());
            logic->SetVelocity(Ball::GetInstance()->getVelocity_x(),
                               Ball::GetInstance()->getVelocity_y());
            logic->Run();
            Point target = logic->Gettarget();

            Message targetMessage;

            targetMessage.message = &target;
            targetMessage.type = red_robot_set_target;

            Messenger::GetInstance()->PostMessageWithoutInforming(targetMessage);
        }
        else
        {
            msg = Messenger::GetInstance()->ReceiveMessage(red_robot_get_velocity);

            if(msg.type==red_robot_get_velocity)
            {
                Velocity* v = (Velocity*)msg.message;
                velocity.vx = v->vx;
                velocity.vy = v->vy;
            }
            else
            {
                Messenger::GetInstance()->PostMessageWithoutInforming(msg);
            }
        }
    }

    void RedRobot::Move_x()
    {
        pos_x+=velocity.vx;
    }

    void RedRobot::Move_y()
    {
        pos_y+=velocity.vy;
    }

    void RedRobot::Move_x(float step)
    {
        pos_x+=step;
    }

    void RedRobot::Move_y(float step)
    {
        pos_y+=step;
    }

    void RedRobot::SetPoint(int pt)
    {
       point = pt;
    }

    int RedRobot::GetPoint() const
    {
        return point;
    }

    float RedRobot::getX(){
        return pos_x;
    }

    float RedRobot::getY(){
        return pos_y;
    }

    int RedRobot::getR(){
        return diameter / 2;
    }

    GreenRobot* GreenRobot::pInstance = NULL;

    GreenRobot* GreenRobot::GetInstance()
    {
        if(pInstance == NULL)
        {
            pInstance=new GreenRobot();
        }
        return pInstance;
    }

    void GreenRobot::Initialize()
    {
        QPixmap pixmap(":/picture/resource/green.png");
        diameter = pixmap.height();
        pos_x = 150;
        pos_y = 440;
        point = 0;
        pixmap.scaled(diameter,diameter,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        texture.setTexture(pixmap);
        edge.setColor(Qt::green);
        edge.setWidth(1);

        logic = new LogicManager();

        velocity.vx = 0;
        velocity.vy = 0;

        connect(Messenger::GetInstance(),
                   SIGNAL(sig_newMessageIn(int)),
                   this,
                   SLOT(Update(int)));
    }

    void GreenRobot::Draw(QPainter *painter)
    {
        painter->save();
        painter->translate(pos_x,pos_y);
        painter->setBrush(texture);
        painter->setPen(edge);
        painter->drawEllipse(0,0,diameter,diameter);
        painter->restore();
    }

    void GreenRobot::Update(int messagetype)
    {
        Message msg = Messenger::GetInstance()->ReceiveMessage(controler_need_green_robot_target);

        if(msg.type==controler_need_green_robot_target)
        {
            logic->SetPosition(Ball::GetInstance()->getX(),Ball::GetInstance()->getY());
            logic->SetVelocity(Ball::GetInstance()->getVelocity_x(),
                               Ball::GetInstance()->getVelocity_y());
            logic->Run();
            Point target = logic->Gettarget();

            Message targetMessage;

            targetMessage.message = &target;
            targetMessage.type = green_robot_set_target;

            Messenger::GetInstance()->PostMessageWithoutInforming(targetMessage);
        }
        else
        {
            msg = Messenger::GetInstance()->ReceiveMessage(green_robot_get_velocity);

            if(msg.type==green_robot_get_velocity)
            {
                Velocity* v = (Velocity*)msg.message;
                velocity.vx = v->vx;
                velocity.vy = v->vy;
            }
            else
            {
                Messenger::GetInstance()->PostMessageWithoutInforming(msg);
            }
        }
    }

    void GreenRobot::Move_x()
    {
        pos_x+=velocity.vx;
    }

    void GreenRobot::Move_y()
    {
        pos_y+=velocity.vy;
    }

    void GreenRobot::Move_x(float step)
    {
        pos_x+=step;
    }

    void GreenRobot::Move_y(float step)
    {
        pos_y+=step;
    }

    void GreenRobot::SetPoint(int pt)
    {
       point = pt;
    }

    int GreenRobot::GetPoint() const
    {
        return point;
    }

    float GreenRobot::getX(){
        return pos_x;
    }

    float GreenRobot::getY(){
        return pos_y;
    }

    int GreenRobot::getR(){
        return diameter / 2;
    }

    Ball* Ball::pInstance = NULL;

    Ball* Ball::GetInstance()
    {
        if(pInstance == NULL)
        {
            pInstance=new Ball();
        }
        return pInstance;
    }

    void Ball::Initialize()
    {
        QPixmap pixmap(":/picture/resource/ball.png");
        diameter = pixmap.height();
        pos_x = 150;
        pos_y = 250;
        pixmap.scaled(diameter,diameter,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        texture.setTexture(pixmap);
        edge.setColor(QColor(255,97,0));
        edge.setWidth(3);

        vx = 0;
        vy = -4;
    }

    void Ball::Draw(QPainter *painter)
    {
        painter->save();
        painter->translate(pos_x,pos_y);
        painter->setBrush(texture);
        painter->setPen(edge);
        painter->drawEllipse(0,0,diameter,diameter);
        painter->restore();
    }

    void Ball::Update(int messagetype)
    {

    }

    void Ball::Move_x(float step)
    {
        pos_x+=step;
    }

    void Ball::Move_y(float step)
    {
        pos_y+=step;
    }

    float Ball::getX(){
        return pos_x;
    }

    float Ball::getY(){
        return pos_y;
    }

    int Ball::getR(){
        return diameter / 2;
    }

    void Ball::SetPosition(float x, float y)
    {
        pos_x = x;
        pos_y = y;
    }

    float Ball::getVelocity_x(){
        return vx;
    }

    float Ball::getVelocity_y(){
        return vy;
    }

    void Ball::setVelocity(float x, float y){
        Ball::GetInstance()->vx = x;
        Ball::GetInstance()->vy = y;
    }

    Arena* Arena::pInstance = NULL;

    Arena* Arena::GetInstance()
    {
        if(pInstance == NULL)
        {
            pInstance=new Arena();
        }
        return pInstance;
    }

    void Arena::Initialize()
    {

    }

    void Arena::Draw(QPainter *painter)
    {

    }

    void Arena::Update(int messagetype)
    {

    }
}
