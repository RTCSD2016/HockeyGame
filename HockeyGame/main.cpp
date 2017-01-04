#include <QApplication>
#include <QSurfaceFormat>
#include "guimain.h"

using namespace Hockey;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setSamples(4);
    QSurfaceFormat::setDefaultFormat(format);

    GuiMain gui;
    gui.show();

    return a.exec();
}
