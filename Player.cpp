#include "Player.h"
#include "gfx/SDL2_rotozoom.h"
#include <iostream>
#include "Bullet.h"
#include "util/fonctionTTF.h"

extern TTF_Font* numberFont;
extern SDL_Color GRIS;

extern SDL_Window *ecran;

Player::Player() : barre(pv,pvMax)
{
    m_sprite=IMG_Load("./data/sprite/tank.png");
    m_spriteTurret=IMG_Load("./data/sprite/turret.png");
    m_height=20;
    m_width=20;
    angleTank=0;
    angleTurret=0;
    speed=2;

    pv=pvMax=20;
    barre.setPosition(10,10);
    barre.setLLL(200,10,2);
    barre.setBackColor(0,20,100);
    barre.setColor(0,230,25);
}

void  Player::init(int x,int y)
{
    m_posX=x;
    m_posY=y;
    pv=pvMax;
    isDamaged=false;
    m_velX=0;
    m_velY=0;
}


Player::~Player()
{
    SDL_FreeSurface(m_sprite);
    SDL_FreeSurface(m_spriteTurret);
}

void Player::affiche()
{
    //affichage caisse tank
    SDL_Surface *imageAfter= rotozoomSurface(m_sprite,angleTank,0.5,0);
    SDL_Rect pos;
    pos.x=SDL_GetWindowSurface(ecran)->w/2-imageAfter->w/2;
    pos.y=SDL_GetWindowSurface(ecran)->h/2-imageAfter->h/2;
    if(isDamaged){
        SDL_SetSurfaceColorMod(imageAfter,255,0,0);
        isDamaged=false;
    }
    SDL_BlitSurface(imageAfter,NULL,SDL_GetWindowSurface(ecran),&pos);
    SDL_FreeSurface(imageAfter);

    // affichage tourel tank
    SDL_Surface *turretAfter= rotozoomSurface(m_spriteTurret,-angleTurret,0.5,0);
    pos.x=SDL_GetWindowSurface(ecran)->w/2-turretAfter->w/2;
    pos.y=SDL_GetWindowSurface(ecran)->h/2-turretAfter->h/2;
    SDL_BlitSurface(turretAfter,NULL,SDL_GetWindowSurface(ecran),&pos);
    SDL_FreeSurface(turretAfter);

    barre.draw(ecran);
//    pos.x=500;
//    pos.y=10;
//    afficheIntSurInt(pos,posX(),posY(),ecran,numberFont,GRIS);

}

void Player::moov()
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

void Player::setMouse(int x,int y)
{
     angle=atan2(y-SDL_GetWindowSurface(ecran)->h/2,x-SDL_GetWindowSurface(ecran)->w/2);
     angleTurret=180*angle/M_PI;
}

void Player::fire()
{
    Bullet bullet(posX()+cos(angle)*30,posY()+sin(angle)*30,angle,Bullet::AMI);
    Bullet::vec.push_back(bullet);
    Mix_PlayChannel(-1, fireSound, 0);
    std::cerr<<"fire"<<std::endl;
}

void Player::damage()
{
    isDamaged=true;
    pv--;
}

void Player::load()
{
    //**************** sfx ****************
    fireSound=Mix_LoadWAV("data/son/Explosion+1.wav");
    if(!fireSound) {
        std::cerr<<"Mix_LoadWAV: "<< Mix_GetError()<<std::endl;
    }
    //**************** sfx *****************
}

void Player::unload()
{
    Mix_FreeChunk(fireSound);
    fireSound=NULL;
}
