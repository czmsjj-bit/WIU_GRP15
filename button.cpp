#include "button.h"
#include "gameobject.h"
#include "door.h"

button::button(int xpos, int ypos, char Icon, bool Lockstatus)
{
    coordinates.Placex(xpos);
    coordinates.Placey(ypos);
    seticon(Icon);
    lockstatus = Lockstatus;

}



//when boulder collides with button this function is imidietly called
void button::openupdoor(gameobject** gameobjectlist) {
    for (int i = 0; i < 10; i++) {
        if (gameobjectlist[i] != nullptr) {
            if (gameobjectlist[i]->geticon() == 'U') {
                gameobjectlist[i]->seticon('N');

                door* thedoor = static_cast<door*>(gameobjectlist[i]);
                thedoor->setopenstatus(true);

                return;
            }
        }
    }
}

void button::setlockstatus(bool stat)
{
    lockstatus = stat;
}

bool button::getlockstatus()
{
    return lockstatus;
}
