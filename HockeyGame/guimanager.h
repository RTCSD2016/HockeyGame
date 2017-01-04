#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <QOpenGLWidget>
#include <QWidget>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include "render.h"

namespace Hockey
{
    class GuiManager : public QWidget
    {
        Q_OBJECT

    public:

        GuiManager(Render* render,QWidget* parent);

    public slots:

        void Update();

    protected:

        void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

    private:

        Render* pRender;
    };
}
#endif // GUIMANAGER_H
