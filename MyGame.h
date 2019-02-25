#ifndef MYGAME_H
#define MYGAME_H

#include "core/Game.h"
#include "Map/FinalMap.h"


class MyGame : public Game
{
    public:
        MyGame();
        virtual ~MyGame();

        void gameOver();

    protected:

    private:
        FinalMap* level1;
};

#endif // MYGAME_H
