#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "util/Barre.h"

class Player
{
    public:
        Player();
        virtual ~Player();

        void affiche();
        bool deplace(int velX, int velY);

        void setPosition(int x,int y){m_posX=x;m_posY=y;}
        int posX(){return m_posX;}
        int posY(){return m_posY;}
        int width(){return m_width;}
        int height(){return m_height;}
        int getPv(){return pv;}

        void setMouse(int x,int y);
        void fire();
        void damage();
        void init(int x,int y);
        void load();
        void unload();

        SDL_Rect hitBox()
        {
            SDL_Rect hitBox;
            hitBox.w=width();
            hitBox.h=height();
            hitBox.x=posX()-width()/2;
            hitBox.y=posY()-height()/2;
            return hitBox;
        }

    protected:

    private:
        SDL_Surface *m_sprite;
        SDL_Surface *m_spriteTurret;
        int m_posX;
        int m_posY;
        int m_width;
        int m_height;

        int angleTank;
        int angleTurret;
        float angle;

        int pv;
        int pvMax;
        Barre barre;

        //**** sfx ******
        Mix_Chunk *fireSound;

};

#endif // PLAYER_H
