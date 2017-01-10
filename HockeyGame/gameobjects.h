#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "gameobject.h"
#include "logicmanager.h"
#include "messenger.h"
#include "messagetypes.h"
#include <QBrush>
#include <QPen>
#include <QObject>

namespace Hockey
{
    class RedRobot : public QObject , public GameObject
    {
        Q_OBJECT
    public:

        void Initialize();
        void Draw(QPainter* painter);

        void Move_x();
        void Move_y();

        void Move_x(float step);
        void Move_y(float step);

        void SetPoint(int pt);
        int GetPoint() const;

        float getX();
        float getY();
        int   getR();

        static RedRobot* GetInstance();

    public slots:

        void Update(int messagetype);

    private:

        QPen        edge;
        QBrush      texture;
        Velocity    velocity;
        int         diameter;
        float       pos_x;
        float       pos_y;
        int         point;


        LogicManager* logic;

        static RedRobot* pInstance;

    };

    class GreenRobot : public QObject , public GameObject
    {
        Q_OBJECT
    public:

        void Initialize();
        void Draw(QPainter* painter);

        void Move_x();
        void Move_y();

        void Move_x(float step);
        void Move_y(float step);

        void SetPoint(int pt);
        int GetPoint() const;

        float getX();
        float getY();
        int   getR();

        static GreenRobot* GetInstance();

    public slots:

        void Update(int messagetype);

    private:

        QPen        edge;
        QBrush      texture;
        Velocity    velocity;
        int         diameter;
        float       pos_x;
        float       pos_y;
        int         point;

        LogicManager* logic;

        static GreenRobot* pInstance;
    };

    class Ball : public GameObject
    {
    public:

        void Initialize();
        void Draw(QPainter* painter);
        void Update(int messagetype);

        void Move_x(float step);
        void Move_y(float step);

        float getX();
        float getY();
        int   getR();

        void  SetPosition(float x,float y);

        float getVelocity_x();
        float getVelocity_y();
        void  setVelocity(float x, float y);

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
        void Update(int messagetype);

        static Arena* GetInstance();

    private:

        QPen    edge;
        QBrush  texture;

        static Arena* pInstance;
    };
}
#endif // GAMEOBJECTS_H
