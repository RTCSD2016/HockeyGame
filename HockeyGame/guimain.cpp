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

        QPushButton* resetButton = new QPushButton(guimanager);

        resetButton->resize(50,20);

        redRobotPoint = new QLineEdit(guimanager);
        greenRobotPoint = new QLineEdit(guimanager);

        QLabel* redRobotPointLabel = new QLabel(guimanager);
        QLabel* greenRobotPointLabel = new QLabel(guimanager);

        redRobotPointLabel->setText(tr("Red Point:"));
        greenRobotPointLabel->setText(tr("Green Point:"));

        resetButton->setText(tr("Reset"));

        QGridLayout* layout = new QGridLayout();
        QGridLayout* menulayout = new QGridLayout();
        QGridLayout* redRobotPointLayout = new QGridLayout();
        QGridLayout* greenRobotPointLayout = new QGridLayout();

        redRobotPointLayout->setColumnMinimumWidth(0,150);
        greenRobotPointLayout->setColumnMinimumWidth(0,150);

        redRobotPointLayout->addWidget(redRobotPointLabel,0,0);
        redRobotPointLayout->addWidget(redRobotPoint,0,1);
        greenRobotPointLayout->addWidget(greenRobotPointLabel,0,0);
        greenRobotPointLayout->addWidget(greenRobotPoint,0,1);

        menulayout->addWidget(resetButton,0,0);
        menulayout->addLayout(redRobotPointLayout,1,0);
        menulayout->addLayout(greenRobotPointLayout,2,0);
        layout->setMargin(0);
        layout->addLayout(menulayout,0,0);
        layout->addWidget(guimanager,1,0);
        setLayout(layout);

        connect(resetButton,SIGNAL(clicked(bool)),this,SLOT(ResetButtonDown(bool)));


        QTimer* timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(UpdatePoint()));
        connect(timer,SIGNAL(timeout()),guimanager,SLOT(Update()));
        timer->start(50);

        rThread.start();
    }

    GuiMain::~GuiMain()
    {

    }

    void GuiMain::keyPressEvent(QKeyEvent *event)
    {
        switch (event->key()) {
        case Qt::Key_W:
            GreenRobot::GetInstance()->Move_y(-10);
            break;
        case Qt::Key_S:
            GreenRobot::GetInstance()->Move_y(10);
            break;
        case Qt::Key_A:
            GreenRobot::GetInstance()->Move_x(-10);
            break;
        case Qt::Key_D:
            GreenRobot::GetInstance()->Move_x(10);
            break;
        case Qt::Key_I:
            RedRobot::GetInstance()->Move_y(-10);
            break;
        case Qt::Key_K:
            RedRobot::GetInstance()->Move_y(10);
            break;
        case Qt::Key_J:
            RedRobot::GetInstance()->Move_x(-10);
            break;
        case Qt::Key_L:
            RedRobot::GetInstance()->Move_x(10);
            break;
        default:
            break;
        }
    }

    void GuiMain::ResetButtonDown(bool b)
    {
        RedRobot::GetInstance()->SetPoint(0);
        GreenRobot::GetInstance()->SetPoint(0);

        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);

        float vx = qrand()%21-10;
        float vy = qrand()%21-10;

        Ball::GetInstance()->SetPosition(150,250);
        Ball::GetInstance()->setVelocity(vx,vy);
    }

    void GuiMain::UpdatePoint()
    {
        redRobotPoint->setText(QString::number(RedRobot::GetInstance()->GetPoint()));
        greenRobotPoint->setText(QString::number(GreenRobot::GetInstance()->GetPoint()));
    }
}

