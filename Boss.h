#ifndef BOSS_H
#define BOSS_H

#include "Eni.h"
#include "util/Barre.h"

class Boss : public Eni
{
    public:
        Boss(int x,int y);
        virtual ~Boss();
        void draw(int playerX,int playerY);
        void damage();
        void fire();

        static void load();
        static void unload();


    protected:

    private:
        bool isDamaged;
        int pv;
        int pvMax;
        Barre barre;

        static SDL_Surface *BossSprite;
        static SDL_Surface *BossTurret;

};

#endif // BOSS_H
