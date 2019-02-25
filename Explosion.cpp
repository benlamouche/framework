#include "Explosion.h"
#include <iostream>
#include <cmath>


extern SDL_Window *ecran;

Explosion::Explosion(int x, int y)
{
    posX=x;
    posY=y;
    m_toDelete=false;
    state=0;
}

Explosion::~Explosion()
{

}

void Explosion::update(int playerX,int playerY)
{
    if(state++ >= 12){
        m_toDelete=true;
    }
}

void Explosion::draw(int playerX,int playerY)
{
    SDL_Rect pos;
    SDL_Rect source;
    source.x=96*state;
    source.y=0;
    source.h=96;
    source.w=96;
    pos.x=SDL_GetWindowSurface(ecran)->w/2+posX-playerX-96/2;
    pos.y=SDL_GetWindowSurface(ecran)->h/2+posY-playerY-96/2;

    //SDL_BlitSurface(sprite,NULL,SDL_GetWindowSurface(ecran),&pos);
    SDL_BlitSurface(sprite,&source,SDL_GetWindowSurface(ecran),&pos);

}

void Explosion::load()
{
    sprite=IMG_Load("./data/sprite/Explosion.png");

}

void Explosion::unload()
{
    SDL_FreeSurface(sprite);
}

vector<Explosion> Explosion::vec;
vector<Explosion>::iterator Explosion::it;
SDL_Surface *Explosion::sprite=NULL;
