#include "Eni.h"
#include "gfx/SDL2_rotozoom.h"
#include <iostream>
#include "Bullet.h"
#include "Explosion.h"
#include "util/benrandom.h"
#include "util/collision.h"

extern SDL_Window *ecran;

Eni::Eni(int x,int y)
{
    m_height=30;
    m_width=30;
    angleTank=0;
    angleTurret=0;

    m_posX=x ;
    m_posY=y ;

    m_isDestroyed=false;

    cooldown=100;
    currentTime=de(cooldown);

    changeDirection();
}

void  Eni::init()
{

}


Eni::~Eni()
{

}

bool Eni::update(int playerX,int playerY)
{
    //rectangle de l'écran
    SDL_Rect ecranRect;
    ecranRect.x=playerX-SDL_GetWindowSurface(ecran)->w/2-m_width;
    ecranRect.y=playerY-SDL_GetWindowSurface(ecran)->h/2-m_height;
    ecranRect.w=SDL_GetWindowSurface(ecran)->w+m_width;
    ecranRect.h=SDL_GetWindowSurface(ecran)->h+m_height;
    //si Eni est dans l'ecran : update
    bool test=false;
    if(pointCollision(posX(),posY(),ecranRect)){
        test=true;
        angle=atan2(playerY-posY(),playerX-posX());
        angleTurret=180*angle/M_PI;
        if (currentTime--<0)
        {
            fire();
            currentTime=cooldown;
        }
    }
    return test;
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

void Eni::moov()
{
    if (velX() < 0){
        if (velY() > 0){
            angleTank=225;
        }else if(velY() < 0){
            angleTank=135;
        }else{
            angleTank=180;
        }
    }else if(velX() > 0){
         if (velY() > 0){
            angleTank=315;
        }else if(velY() < 0){
            angleTank=45;
        }else{
            angleTank=0;
        }
    }else{
         if (velY() > 0){
            angleTank=270;
        }else if(velY() < 0){
            angleTank=90;
        }else{

        }
    }

    m_posX+=velX();
    m_posY+=velY();

}

void Eni::fire()
{
    Bullet bullet(posX()+cos(angle)*30,posY()+sin(angle)*30,angle,Bullet::ENI);
    Bullet::vec.push_back(bullet);
    Mix_PlayChannel(-1, fireSound, 0);
}

void Eni::damage()
{
    Explosion::vec.push_back(Explosion(posX(),posY()));

    m_isDestroyed=true;
}

void Eni::load()
{
    m_sprite=IMG_Load("./data/sprite/Eni.png");
    m_spriteTurret=IMG_Load("./data/sprite/EniTurret.png");

    //**************** sfx ****************
    fireSound=Mix_LoadWAV("data/son/Explosion+1.wav");
    if(!fireSound) {
        std::cerr<<"Mix_LoadWAV: "<< Mix_GetError()<<std::endl;
    }
    //**************** sfx *****************
}

void Eni::unload()
{
    SDL_FreeSurface(m_sprite);
    SDL_FreeSurface(m_spriteTurret);
    //**************** sfx ****************
    Mix_FreeChunk(fireSound);
    fireSound=NULL;
    //**************** sfx ****************
}

void Eni::changeDirection()
{
    m_velX=random(2);
    if(m_velX>1)m_velX=-1;
    m_velY=random(2);
    if(m_velY>1)m_velY=-1;

    if(m_velY==0 && m_velX==0)changeDirection();
}

SDL_Surface * Eni::m_sprite=NULL;
SDL_Surface * Eni::m_spriteTurret=NULL;
Mix_Chunk * Eni::fireSound=NULL;
