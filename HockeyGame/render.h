#ifndef RENDER_H
#define RENDER_H

#include <QPainter>
#include <QPaintEvent>
#include <vector>
#include "gameobject.h"

namespace Hockey
{
    class Render
    {
    public:

        Render();

    public:

        void render(QPainter* painter,QPaintEvent* event);

        void Initialize();

        void AddGameObject(GameObject* obj);

    private:

        std::vector<GameObject*> RenderList;
    };
}

#endif // RENDER_H
