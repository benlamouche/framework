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
        void switchFullScreen();

    protected:

    private:
        Scene* menuIntro;
        FinalMap* level1;
        FinalMap* level2;
        FinalMap* level3;
        bool FullScreen;
};

#endif // MYGAME_H
