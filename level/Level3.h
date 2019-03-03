#ifndef LEVEL3_H
#define LEVEL3_H

#include "../Map/FinalMap.h"


class Level3 : public FinalMap
{
    public:
        Level3();
        virtual ~Level3();

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

#endif // LEVEL3_H
