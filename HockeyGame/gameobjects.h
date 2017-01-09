#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "gameobject.h"
#include <QBrush>
#include <QPen>

namespace Hockey
{
    class RedRobot : public GameObject
    {
    public:

        void Initialize();
        void Draw(QPainter* painter);
        void Update();

        void Move_x(float step);
        void Move_y(float step);

        float getX();
        float getY();
        int getR();

        static RedRobot* GetInstance();

    private:

        QPen    edge;
        QBrush  texture;
        int     diameter;
        float     pos_x;
        float     pos_y;

        static RedRobot* pInstance;

    };

    class GreenRobot : public GameObject
    {
    public:

        void Initialize();
        void Draw(QPainter* painter);
        void Update();

        void Move_x(float step);
        void Move_y(float step);

        float getX();
        float getY();
        int getR();

        static GreenRobot* GetInstance();

    private:

        QPen    edge;
        QBrush  texture;
        int     diameter;
        float     pos_x;
        float     pos_y;

        static GreenRobot* pInstance;
    };

    class Ball : public GameObject
    {
    public:

        void Initialize();
        void Draw(QPainter* painter);
        void Update();

        void Move_x(float step);
        void Move_y(float step);

        float getX();
        float getY();
        int getR();

        float getVelocity_x();
        float getVelocity_y();
        void setVelocity(float x, float y);

        static Ball* GetInstance();

    private:

        QPen    edge;
        QBrush  texture;
        int     diameter;
        float     pos_x;
        float     pos_y;

        //Velocity variable. Representing the pixels the ball moves through in 20 ms.
        float     vx;
        float     vy;

        static Ball* pInstance;
    };

    class Arena : public GameObject
    {
    public:

        void Initialize();
        void Draw(QPainter* painter);
        void Update();

        static Arena* GetInstance();

    private:

        QPen    edge;
        QBrush  texture;

        static Arena* pInstance;
    };
}
#endif // GAMEOBJECTS_H
