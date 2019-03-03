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
        void moov();

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

        void goSouth(){m_velY=speed;}
        void goNorth(){m_velY=-speed;}
        void goEast(){m_velX=speed;}
        void goWest(){m_velX=-speed;}

        void stopSouth(){m_velY=m_velY==speed?0:m_velY;}
        void stopNorth(){m_velY=m_velY==-speed?0:m_velY;}
        void stopEast(){m_velX=m_velX==speed?0:m_velX;}
        void stopWest(){m_velX=m_velX==-speed?0:m_velX;}


        int velX(){return m_velX;}
        int velY(){return m_velY;}

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

        int speed;
        int m_velX;
        int m_velY;

        bool isDamaged;

        //**** sfx ******
        Mix_Chunk *fireSound;

};

#endif // PLAYER_H
