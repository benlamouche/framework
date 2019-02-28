#include "GoLevel.h"
#include "../core/Game.h"
#include "../MyGame.h"

extern Game* game;

GoLevel::GoLevel(int level ,const char* name):ElementMenu(name)
{
    //ctor
    m_level=level;

}

GoLevel::~GoLevel()
{
    //dtor
}

int GoLevel::action(int val)
{
    dynamic_cast<MyGame *>(game)->goScene(m_level);
    return val;
}

