#ifndef GUIMAIN_H
#define GUIMAIN_H

#include <QWidget>
#include <QGridLayout>
#include <QTimer>
#include <QLabel>
#include <QPixmap>
#include "render.h"
#include "guimanager.h"
#include "gameobjects.h"

namespace Hockey
{
    class GuiMain : public QWidget
    {
    public:

        GuiMain();

    public slots:

        void keyPressEvent(QKeyEvent *event);

    private:

        Render render;
    };
}


#endif // GUIMAIN_H
