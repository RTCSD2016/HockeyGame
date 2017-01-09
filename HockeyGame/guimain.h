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
#include "collision.h"
#include "runthread.h"

namespace Hockey
{
    class GuiMain : public QWidget
    {
    public:

        GuiMain();

    public slots:

        void keyPressEvent(QKeyEvent *event);
        //static DWORD WINAPI rThread(LPVOID pvoid);    //avaliable only on Windows

    private:

        Render render;
        RunThread rThread;

    };
}


#endif // GUIMAIN_H
