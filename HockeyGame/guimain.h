#ifndef GUIMAIN_H
#define GUIMAIN_H

#include <QWidget>
#include <QGridLayout>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QLineEdit>
#include "render.h"
#include "guimanager.h"
#include "gameobjects.h"
#include "collision.h"
#include "runthread.h"

class QWidget;

namespace Hockey
{
    class GuiMain : public QWidget
    {
        Q_OBJECT

    public:

        GuiMain();
        ~GuiMain();

    private slots:

        void keyPressEvent(QKeyEvent *event);

        void ResetButtonDown(bool b);

        void UpdatePoint();

    private:

        Render render;
        RunThread rThread;

        QLineEdit* redRobotPoint;
        QLineEdit* greenRobotPoint;

    };
}


#endif // GUIMAIN_H
