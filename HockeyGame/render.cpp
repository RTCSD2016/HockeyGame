#include "render.h"

namespace Hockey
{
    Render::Render()
    {

    }

    void Render::Initialize()
    {
        for(GameObject* object : RenderList)
        {
            object->Initialize();
        }
    }

    void Render::render(QPainter* painter,QPaintEvent* event)
    {
        for(GameObject* object : RenderList)
        {
            object->Draw(painter);
        }
    }

    void Render::AddGameObject(GameObject *obj)
    {
        RenderList.push_back(obj);
    }
}
