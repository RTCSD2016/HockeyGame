#include "guirefresh.h"

namespace Hockey{
/*
 *
 * Used for refreshing the UI
 *
 */
    class GuiRefresh{

        GuiRefresh(){

        }

        static DWORD WINAPI rThread(LPVOID pvoid){
            while(true){
                Ball::GetInstance()->Move_x(Ball::GetInstance()->getVelocity_x());
                Ball::GetInstance()->Move_y(Ball::GetInstance()->getVelocity_y());
                Sleep(20);
            }
        }

    };
}
