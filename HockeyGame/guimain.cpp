#include "guimain.h"

namespace Hockey
{
    /*
     *
     * The Entry Of The Programm
     *
     */
    GuiMain::GuiMain()
    {
        setWindowTitle(tr("HockeyGame"));

        render.AddGameObject(RedRobot::GetInstance());
        render.AddGameObject(GreenRobot::GetInstance());
        render.AddGameObject(Ball::GetInstance());
        render.AddGameObject(Arena::GetInstance());

        render.Initialize();

        GuiManager* guimanager = new GuiManager(&render,this);

        QGridLayout* layout = new QGridLayout();
        layout->setMargin(0);
        layout->addWidget(guimanager,0,0);
        setLayout(layout);

        QTimer* timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),guimanager,SLOT(Update()));
        timer->start(50);
    }

    void GuiMain::keyPressEvent(QKeyEvent *event)
    {
        switch (event->key()) {
        case Qt::Key_W:
            RedRobot::GetInstance()->Move_y(-5);
            break;
        case Qt::Key_S:
            RedRobot::GetInstance()->Move_y(5);
            break;
        case Qt::Key_A:
            RedRobot::GetInstance()->Move_x(-5);
            break;
        case Qt::Key_D:
            RedRobot::GetInstance()->Move_x(5);
            break;
        default:
            break;
        }
    }
}

