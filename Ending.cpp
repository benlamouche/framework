#include "Ending.h"

#include "Scene/ScreenMessage.h"
#include "MyGame.h"

int intro();

Ending::Ending()
{
    //ctor
}

Ending::~Ending()
{
    //dtor
}


void Ending::load()
{

}

void Ending::unload()
{

}

void Ending::update(int dt)
{
        switch(event.type)
        {
            case SDL_QUIT:
                loop=0;
                break;
            case SDL_KEYDOWN:
                loop=0;
                break;
        }


    ScreenMessage::loach("Congratulation",this);
    ScreenMessage::loach("Comming soon",this);
    ScreenMessage::loach("my next game",this);
    intro();
    exit();
    dynamic_cast<MyGame *>(game)->goScene(0);
}

void Ending::draw()
{

}
