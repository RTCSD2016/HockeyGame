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

        rThread.start();

        //HANDLE thread = CreateThread(NULL, 0, rThread, NULL, 0, NULL);    //Abandoned.
    }

    void GuiMain::keyPressEvent(QKeyEvent *event)
    {
        switch (event->key()) {
        case Qt::Key_W:
            GreenRobot::GetInstance()->Move_y(-5);
            break;
        case Qt::Key_S:
            GreenRobot::GetInstance()->Move_y(5);
            break;
        case Qt::Key_A:
            GreenRobot::GetInstance()->Move_x(-5);
            break;
        case Qt::Key_D:
            GreenRobot::GetInstance()->Move_x(5);
            break;
        default:
            break;
        }
    }
    /*
     *
     * Abandoned Method
     *
     *
    DWORD WINAPI GuiMain::rThread(LPVOID pvoid){
        while(true){
            Ball::GetInstance()->Move_x(Ball::GetInstance()->getVelocity_x());
            Ball::GetInstance()->Move_y(Ball::GetInstance()->getVelocity_y());
            Collision::getInstance()->checkCls();
            Sleep(20);
        }
     }
     */
}

