#include "ScreenMessage.h"
#include <iostream>
#include <cstdio>
#include "../core/Game.h"
#include "../util/fonctionTTF.h"

extern Game* game;

extern SDL_Window *ecran;//  main.cpp
extern TTF_Font* numberFont;
extern TTF_Font* texteFont;
//  fonctionTTF.cpp
extern SDL_Color ROUGE ;

ScreenMessage::ScreenMessage(Scene* parent):Scene(parent)
{
    //ctor
    setRGB(50,50,100);
    delayInit=50;
}

ScreenMessage::~ScreenMessage()
{
    //dtor
}

void ScreenMessage::load()
{
  std::cerr<<"load ScreenMessage"<<std::endl;
  delay = delayInit;
}

void ScreenMessage::unload()
{
    std::cerr<<"unload ScreenMessage"<<std::endl;
}

void ScreenMessage::update(int dt)
{
    switch(event.type)
    {
        case SDL_QUIT:
            game->quit();
            break;
    }

    delay--;

    if (delay <= 0)loop=0;
    if(game->status()==QUIT)loop = 0;
}

void ScreenMessage::draw()
{
    parent()->draw();
    SDL_Rect position;
    position.x=250;
    position.y=200;
    afficheTexte(position,m_text,ecran,texteFont,ROUGE);
}

void ScreenMessage::setText(const char* text)
{
    sprintf(m_text,text);
}

void ScreenMessage::loach(const char * text,Scene* parent)
{
    std::cerr<<"loach ScreenMessage"<<std::endl;
    ScreenMessage* screenMessage = new ScreenMessage(parent);
    screenMessage->setText(text);
    screenMessage->exec();
    delete screenMessage;
}
