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

        void draw(int, int);
        void update(int,int);
        void deplace(int velX, int velY);

        void setPosition(int x,int y){m_posX=x;m_posY=y;}
        int posX(){return m_posX;}
        int posY(){return m_posY;}
        int width(){return m_width;}
        int height(){return m_height;}

        bool isDestroyed(){return m_isDestroyed;}
        void destroy();

        void fire();
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

        static void load();
        static void unload();

        static vector<Eni> vec;
        static vector<Eni>::iterator it;


    protected:

    private:
        static SDL_Surface *m_sprite;
        static SDL_Surface *m_spriteTurret;

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

        //**** sfx ******
        static Mix_Chunk *fireSound;


};

#endif // ENI_H
