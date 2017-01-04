#include "guimanager.h"

namespace Hockey
{
    GuiManager::GuiManager(Render *render, QWidget *parent)
        : QWidget(parent),pRender(render)
    {
        QPixmap background(":/picture/table.png");

        setFixedSize(300,500);
        setAutoFillBackground(true);

        QPalette palette = this->palette();
        palette.setBrush(QPalette::Background,QBrush(background));
        this->setPalette(palette);
    }

    void GuiManager::Update()
    {
        update();
    }

    void GuiManager::paintEvent(QPaintEvent* event)
    {
        QPainter painter;
        painter.begin(this);
        painter.setRenderHint(QPainter::Antialiasing);
        pRender->render(&painter,event);
        painter.end();
    }
}
