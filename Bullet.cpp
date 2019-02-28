#include "Bullet.h"

#include <cmath>
#include <SDL_image.h>

extern SDL_Window *ecran;

Bullet::Bullet(int x, int y, float angle,from fm)
{
    posX=x;
    posY=y;
    velX=cos(angle)*10;
    velY=sin(angle)*10;
    m_toDelete=false;
    frm=fm;
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
    SDL_Surface *sprite;
    if(frm==AMI){
        sprite=m_sprite1;
    }else{
        sprite=m_sprite2;
    }
    pos.x=SDL_GetWindowSurface(ecran)->w/2+posX-playerX-3;
    pos.y=SDL_GetWindowSurface(ecran)->h/2+posY-playerY-3;

    SDL_BlitSurface(sprite,NULL,SDL_GetWindowSurface(ecran),&pos);
}

void Bullet::load()
{
    m_sprite1=IMG_Load("./data/sprite/bullet1.png");
    m_sprite2=IMG_Load("./data/sprite/bullet2.png");
}

void Bullet::unload()
{
    SDL_FreeSurface(m_sprite1);
    SDL_FreeSurface(m_sprite2);
}

vector<Bullet> Bullet::vec;
vector<Bullet>::iterator Bullet::it;
SDL_Surface * Bullet::m_sprite1=NULL;
SDL_Surface * Bullet::m_sprite2=NULL;
