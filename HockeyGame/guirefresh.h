#ifndef GUIREFRESH_H
#define GUIREFRESH_H

#include <Windows.h>
#include "gameobjects.h"

namespace Hockey{
    class GuiRefresh{

    public:

        GuiRefresh();

        static DWORD WINAPI rThread(LPVOID pvoid);

    };
}

#endif // GUIREFRESH_H
