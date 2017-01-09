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
        QPixmap pixmap(":/picture/red.png");
        diameter = pixmap.height();
        pos_x = 150;
        pos_y = 60;
        pixmap.scaled(diameter,diameter,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        texture.setTexture(pixmap);
        edge.setColor(QColor(255,0,255));
        edge.setWidth(1);
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

    void RedRobot::Update()
    {

    }

    void RedRobot::Move_x(float step)
    {
        pos_x+=step;
    }

    void RedRobot::Move_y(float step)
    {
        pos_y+=step;
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
        QPixmap pixmap(":/picture/green.png");
        diameter = pixmap.height();
        pos_x = 150;
        pos_y = 440;
        pixmap.scaled(diameter,diameter,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        texture.setTexture(pixmap);
        edge.setColor(Qt::green);
        edge.setWidth(1);
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

    void GreenRobot::Update()
    {

    }

    void GreenRobot::Move_x(float step)
    {
        pos_x+=step;
    }

    void GreenRobot::Move_y(float step)
    {
        pos_y+=step;
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
        QPixmap pixmap(":/picture/ball.png");
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

    void Ball::Update()
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

    void Arena::Update()
    {

    }
}
