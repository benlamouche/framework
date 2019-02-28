#ifndef LEVEL2_H
#define LEVEL2_H

#include "../Map/FinalMap.h"


class Level2 : public FinalMap
{
    public:
        Level2();
        virtual ~Level2();

    protected:

    private:
        void loadMusic();
        void unloadMusic();
        void initEni();
        void initPlayer();
        void goNextLevel();

        Mix_Music *musique;
};

#endif // LEVEL2_H
