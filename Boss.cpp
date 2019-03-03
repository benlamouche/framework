#include "Boss.h"
#include "Bullet.h"
#include "gfx/SDL2_rotozoom.h"
#include "Explosion.h"

extern SDL_Window *ecran;

Boss::Boss(int x,int y):Eni(x,y),barre(pv,pvMax)
{
    isDamaged=false;
    m_height=50;
    m_width=50;
    pv=pvMax=50;
    cooldown=50;

    barre.setPosition(800,10);
    barre.setLLL(200,10,2);
    barre.setBackColor(0,20,100);
    barre.setColor(230,25,25);
}

Boss::~Boss()
{
    //dtor
}

void Boss::load()
{
    BossSprite=IMG_Load("./data/sprite/caisse_boss.png");
    BossTurret=IMG_Load("./data/sprite/tourelle_boss2.png");
}

void Boss::unload()
{
    SDL_FreeSurface(BossSprite);
    SDL_FreeSurface(BossTurret);
}

void Boss::damage()
{
    isDamaged=true;
    pv--;
    if(pv<=0){
        m_isDestroyed=true;
        Explosion::vec.push_back(Explosion(posX(),posY()));
    }
}

void Boss::fire()
{
    Bullet bullet(posX()+cos(angle)*30,posY()+sin(angle)*30,angle,Bullet::ENI);
    Bullet::vec.push_back(bullet);
    Bullet bullet2(posX()+cos(angle+M_PI/6)*30,posY()+sin(angle+M_PI/6)*30,angle,Bullet::ENI);
    Bullet::vec.push_back(bullet2);
    Bullet bullet3(posX()+cos(angle-M_PI/6)*30,posY()+sin(angle-M_PI/6)*30,angle,Bullet::ENI);
    Bullet::vec.push_back(bullet3);
    Mix_PlayChannel(-1, fireSound, 0);
}

void Boss::draw(int playerX,int playerY)
{
    if(!isDestroyed()){
        //affichage caisse tank
        SDL_Surface *imageAfter= rotozoomSurface(BossSprite,angleTank,1,0);
        SDL_Rect pos;
        pos.x=SDL_GetWindowSurface(ecran)->w/2+m_posX-playerX-imageAfter->w/2;
        pos.y=SDL_GetWindowSurface(ecran)->h/2+m_posY-playerY-imageAfter->h/2;
        if(isDamaged){
            SDL_SetSurfaceColorMod(imageAfter,255,0,0);
            isDamaged=false;
        }
        SDL_BlitSurface(imageAfter,NULL,SDL_GetWindowSurface(ecran),&pos);
        SDL_FreeSurface(imageAfter);

        // affichage tourel tank
        SDL_Surface *turretAfter= rotozoomSurface(BossTurret,-angleTurret,1,0);
        pos.x=SDL_GetWindowSurface(ecran)->w/2+m_posX-playerX-turretAfter->w/2;
        pos.y=SDL_GetWindowSurface(ecran)->h/2+m_posY-playerY-turretAfter->h/2;
        SDL_BlitSurface(turretAfter,NULL,SDL_GetWindowSurface(ecran),&pos);
        SDL_FreeSurface(turretAfter);
    }
    barre.draw(ecran);
}

SDL_Surface * Boss::BossSprite=NULL;
SDL_Surface * Boss::BossTurret=NULL;
