#include "FullScreen.h"
#include "../MyGame.h"


FullScreen::FullScreen(const char* name):ElementMenu(name)
{
    //ctor


}

FullScreen::~FullScreen()
{
    //dtor
}

int FullScreen::action(int val)
{
    dynamic_cast<MyGame *>(game)->switchFullScreen();
    return val;
}

