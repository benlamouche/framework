#ifndef ENI_H
#define ENI_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <vector>
using namespace std;

class Eni
{
    public:
        Eni(int x,int y);
        virtual ~Eni();

        virtual void draw(int, int);
        bool update(int,int);
        void moov();
        void changeDirection();

        void setPosition(int x,int y){m_posX=x;m_posY=y;}
        int posX(){return m_posX;}
        int posY(){return m_posY;}
        int width(){return m_width;}
        int height(){return m_height;}

        bool isDestroyed(){return m_isDestroyed;}
        virtual void damage();

        virtual void fire();
        void init();

        SDL_Rect hitBox()
        {
            SDL_Rect hitBox;
            hitBox.w=width();
            hitBox.h=height();
            hitBox.x=posX()-width()/2;
            hitBox.y=posY()-height()/2;
            return hitBox;
        }

        int velX(){return m_velX;}
        int velY(){return m_velY;}

        static void load();
        static void unload();


    protected:

        int m_posX;
        int m_posY;
        int m_width;
        int m_height;

        int angleTank;
        int angleTurret;
        float angle;

        bool m_isDestroyed;
        int cooldown;
        int currentTime;

        int m_velX;
        int m_velY;

        //**** sfx ******
        static Mix_Chunk *fireSound;

private:
        static SDL_Surface *m_sprite;
        static SDL_Surface *m_spriteTurret;

};

#endif // ENI_H
