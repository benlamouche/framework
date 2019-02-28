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
        void goScene(int level);

    protected:

    private:
        FinalMap* level1;
        FinalMap* level2;
};

#endif // MYGAME_H
