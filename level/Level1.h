#ifndef LEVEL1_H
#define LEVEL1_H

#include "../Map/FinalMap.h"


class Level1 : public FinalMap
{
    public:
        Level1();
        virtual ~Level1();

    protected:

    private:
        void loadMusic();
        void unloadMusic();
        void loadEnis();
        void unloadEnis();
        void initPlayer();
        void goNextLevel();

        Mix_Music *musique;
};

#endif // LEVEL1_H
