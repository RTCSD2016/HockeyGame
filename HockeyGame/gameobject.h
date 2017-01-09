#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QPainter>

namespace Hockey
{
    class GameObject
    {

    public:

        virtual void Initialize() = 0;
        virtual void Draw(QPainter* painter) = 0;
        virtual void Update() = 0;

    };
}

#endif // GAMEOBJECT_H
