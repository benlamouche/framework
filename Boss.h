#ifndef BOSS_H
#define BOSS_H

#include "Eni.h"


class Boss : public Eni
{
    public:
        Boss(int x,int y);
        virtual ~Boss();
        void draw(int playerX,int playerY);

        static void load();
        static void unload();


    protected:

    private:
        static SDL_Surface *BossSprite;
        static SDL_Surface *BossTurret;

};

#endif // BOSS_H
