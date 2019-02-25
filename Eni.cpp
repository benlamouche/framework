#include "Eni.h"
#include "gfx/SDL2_rotozoom.h"
#include <iostream>
#include "Bullet.h"
#include "Explosion.h"
#include "util/benrandom.h"

extern SDL_Window *ecran;

Eni::Eni(int x,int y)
{
    m_height=20;
    m_width=20;
    angleTank=0;
    angleTurret=0;

    m_posX=x ;
    m_posY=y ;

    m_isDestroyed=false;

    cooldown=50;
    currentTime=de(cooldown);
}

void  Eni::init()
{

}


Eni::~Eni()
{

}

void Eni::update(int playerX,int playerY)
{

    angle=atan2(playerY-posY(),playerX-posX());
    angleTurret=180*angle/M_PI;
    if (currentTime--<0)
    {
        fire();
        currentTime=cooldown;
    }
}

void Eni::draw(int playerX,int playerY)
{
    if(!isDestroyed()){
        //affichage caisse tank
        SDL_Surface *imageAfter= rotozoomSurface(m_sprite,angleTank,0.5,0);
        SDL_Rect pos;
        pos.x=SDL_GetWindowSurface(ecran)->w/2+m_posX-playerX-imageAfter->w/2;
        pos.y=SDL_GetWindowSurface(ecran)->h/2+m_posY-playerY-imageAfter->h/2;
        SDL_BlitSurface(imageAfter,NULL,SDL_GetWindowSurface(ecran),&pos);
        SDL_FreeSurface(imageAfter);

        // affichage tourel tank
        SDL_Surface *turretAfter= rotozoomSurface(m_spriteTurret,-angleTurret,0.5,0);
        pos.x=SDL_GetWindowSurface(ecran)->w/2+m_posX-playerX-turretAfter->w/2;
        pos.y=SDL_GetWindowSurface(ecran)->h/2+m_posY-playerY-turretAfter->h/2;
        SDL_BlitSurface(turretAfter,NULL,SDL_GetWindowSurface(ecran),&pos);
        SDL_FreeSurface(turretAfter);
    }

}

void Eni::deplace(int velX, int velY)
{
    if (velX < 0){
        if (velY > 0){
            angleTank=225;
        }else if(velY < 0){
            angleTank=135;
        }else{
            angleTank=180;
        }
    }else if(velX > 0){
         if (velY > 0){
            angleTank=315;
        }else if(velY < 0){
            angleTank=45;
        }else{
            angleTank=0;
        }
    }else{
         if (velY > 0){
            angleTank=270;
        }else if(velY < 0){
            angleTank=90;
        }else{

        }
    }

    m_posX+=velX;
    m_posY+=velY;

}

void Eni::fire()
{
    Bullet bullet(posX()+cos(angle)*30,posY()+sin(angle)*30,angle);
    Bullet::vec.push_back(bullet);
}

void Eni::destroy()
{
    Explosion::vec.push_back(Explosion(posX(),posY()));

    m_isDestroyed=true;
}

void Eni::load()
{
    m_sprite=IMG_Load("./data/sprite/Eni.png");
    m_spriteTurret=IMG_Load("./data/sprite/EniTurret.png");
}

void Eni::unload()
{
    SDL_FreeSurface(m_sprite);
    SDL_FreeSurface(m_spriteTurret);
}
vector<Eni> Eni::vec;
vector<Eni>::iterator Eni::it;
SDL_Surface * Eni::m_sprite=NULL;
SDL_Surface * Eni::m_spriteTurret=NULL;
