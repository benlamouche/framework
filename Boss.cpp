#include "Boss.h"

#include "gfx/SDL2_rotozoom.h"

extern SDL_Window *ecran;

Boss::Boss(int x,int y):Eni(x,y)
{
    //ctor
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

void Boss::draw(int playerX,int playerY)
{
    if(!isDestroyed()){
        //affichage caisse tank
        SDL_Surface *imageAfter= rotozoomSurface(BossSprite,angleTank,1,0);
        SDL_Rect pos;
        pos.x=SDL_GetWindowSurface(ecran)->w/2+m_posX-playerX-imageAfter->w/2;
        pos.y=SDL_GetWindowSurface(ecran)->h/2+m_posY-playerY-imageAfter->h/2;
        SDL_BlitSurface(imageAfter,NULL,SDL_GetWindowSurface(ecran),&pos);
        SDL_FreeSurface(imageAfter);

        // affichage tourel tank
        SDL_Surface *turretAfter= rotozoomSurface(BossTurret,-angleTurret,1,0);
        pos.x=SDL_GetWindowSurface(ecran)->w/2+m_posX-playerX-turretAfter->w/2;
        pos.y=SDL_GetWindowSurface(ecran)->h/2+m_posY-playerY-turretAfter->h/2;
        SDL_BlitSurface(turretAfter,NULL,SDL_GetWindowSurface(ecran),&pos);
        SDL_FreeSurface(turretAfter);
    }
}

SDL_Surface * Boss::BossSprite=NULL;
SDL_Surface * Boss::BossTurret=NULL;
