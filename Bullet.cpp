#include "Bullet.h"

#include <cmath>
#include <SDL.h>

extern SDL_Window *ecran;

Bullet::Bullet(int x, int y, float angle)
{
    posX=x;
    posY=y;
    velX=cos(angle)*10;
    velY=sin(angle)*10;
    m_toDelete=false;
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::update(int playerX,int playerY)
{
    posX+=velX;
    posY+=velY;

    if(posX>playerX+SDL_GetWindowSurface(ecran)->w/2 || posX<playerX-SDL_GetWindowSurface(ecran)->w/2
       || posY>playerY+SDL_GetWindowSurface(ecran)->h/2 || posY<playerY-SDL_GetWindowSurface(ecran)->h/2){
            m_toDelete=true;
       }
}

void Bullet::draw(int playerX,int playerY)
{
    SDL_Rect pos;
    SDL_Surface *m_spriteTest=SDL_CreateRGBSurface(0,4,4,32,0,0,0,0);
    SDL_FillRect(m_spriteTest,NULL,SDL_MapRGB(SDL_GetWindowSurface(ecran)->format,255,0,0));

    pos.x=SDL_GetWindowSurface(ecran)->w/2+posX-playerX;
    pos.y=SDL_GetWindowSurface(ecran)->h/2+posY-playerY;

    SDL_BlitSurface(m_spriteTest,NULL,SDL_GetWindowSurface(ecran),&pos);
    SDL_FreeSurface(m_spriteTest);

}

vector<Bullet> Bullet::vec;
vector<Bullet>::iterator Bullet::it;
