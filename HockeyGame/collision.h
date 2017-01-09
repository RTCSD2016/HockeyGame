#ifndef COLLISION_H
#define COLLISION_H

#include <math.h>
#include <QDebug>
#include "gameobjects.h"

namespace Hockey{
    class Collision{

    public:

        Collision();

    public:

        int checkCls();

        void bounce_sides();
        void bounce_tb();
        void col_RR();
        void col_GR();

        static Collision* getInstance();

    private:

        static Collision* col;
        Ball* ball = Ball::GetInstance();

    };
}

#endif // COLLISION_H
