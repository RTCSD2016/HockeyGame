#ifndef RUNTHREAD_H
#define RUNTHREAD_H

#include <QThread>
#include <QDebug>

namespace Hockey
{
class RunThread : public QThread{

public:

    RunThread();

protected:

    void run();

};
}

#endif // RUNTHREAD_H
