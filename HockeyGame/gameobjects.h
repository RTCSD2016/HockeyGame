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

        void Move_x(int step);
        void Move_y(int step);

        static RedRobot* GetInstance();

    private:

        QPen    edge;
        QBrush  texture;
        int     radius;
        int     pos_x;
        int     pos_y;

        static RedRobot* pInstance;

    };

    class GreenRobot : public GameObject
    {
    public:

        void Initialize();
        void Draw(QPainter* painter);
        void Update();

        void Move_x(int step);
        void Move_y(int step);

        static GreenRobot* GetInstance();

    private:

        QPen    edge;
        QBrush  texture;
        int     radius;
        int     pos_x;
        int     pos_y;

        static GreenRobot* pInstance;
    };

    class Ball : public GameObject
    {
    public:

        void Initialize();
        void Draw(QPainter* painter);
        void Update();

        void Move_x(int step);
        void Move_y(int step);

        static Ball* GetInstance();

    private:

        QPen    edge;
        QBrush  texture;
        int     radius;
        int     pos_x;
        int     pos_y;

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
