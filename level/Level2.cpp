#include "Level2.h"
#include <iostream>
#include "../Player.h"
#include "../MyGame.h"
#include "../Boss.h"
extern Player player;

Level2::Level2(): FinalMap("data/map/level2.mp","data/map/wmap.png")
{
    //ctor
}

Level2::~Level2()
{
    //dtor
}

void Level2::initPlayer()
{
    player.init(900,2350);
}

void Level2::loadEnis()
{
    //desert 1
    enis.push_back(new Eni( 550,1900));
    enis.push_back(new Eni( 650,1850));
    enis.push_back(new Eni( 750,1900));
    enis.push_back(new Eni( 850,1850));
    enis.push_back(new Eni( 950,1900));
    enis.push_back(new Eni( 1050,1850));
    enis.push_back(new Eni( 1150,1900));
    enis.push_back(new Eni( 1250,1850));

    enis.push_back(new Eni( 550,1700));
    enis.push_back(new Eni( 650,1500));
    enis.push_back(new Eni( 750,1600));
    enis.push_back(new Eni( 850,1750));
    enis.push_back(new Eni( 950,1650));
    enis.push_back(new Eni( 1050,1800));
    enis.push_back(new Eni( 1150,1750));
    enis.push_back(new Eni( 1250,1800));

    enis.push_back(new Eni( 550,1400));
    enis.push_back(new Eni( 650,1400));
    enis.push_back(new Eni( 750,1500));
    enis.push_back(new Eni( 850,1700));
    enis.push_back(new Eni( 950,1300));
    enis.push_back(new Eni( 1050,1700));
    enis.push_back(new Eni( 1150,1500));
    enis.push_back(new Eni( 1250,1300));

    enis.push_back(new Eni( 550,1000));
    enis.push_back(new Eni( 650,1300));
    enis.push_back(new Eni( 750,1000));
    enis.push_back(new Eni( 850,1250));
    enis.push_back(new Eni( 950,900));
    enis.push_back(new Eni( 1050,1250));
    enis.push_back(new Eni( 1150,1100));

    enis.push_back(new Eni( 600,400));
    enis.push_back(new Eni( 700,600));
    enis.push_back(new Eni( 600,650));

    //plaine
    enis.push_back(new Eni( 1200,800));
    enis.push_back(new Eni( 1100,450));
    enis.push_back(new Eni( 1700,1000));
    enis.push_back(new Eni( 1500,900));
    enis.push_back(new Eni( 1300,600));
    enis.push_back(new Eni( 1100,600));
    enis.push_back(new Eni( 1500,650));
    enis.push_back(new Eni( 1400,800));

    enis.push_back(new Eni( 1900,800));
    enis.push_back(new Eni(1800 ,450));
    enis.push_back(new Eni( 2000,1000));
    enis.push_back(new Eni( 1900,900));
    enis.push_back(new Eni( 1700,600));
    enis.push_back(new Eni( 1800,600));
    enis.push_back(new Eni( 2000,650));
    enis.push_back(new Eni( 1900,800));

//desert 2
    enis.push_back(new Eni( 1650,1300));
    enis.push_back(new Eni( 2200,2400));
    enis.push_back(new Eni( 1700,1500));
    enis.push_back(new Eni( 1800,2000));
    enis.push_back(new Eni( 1700,1800));
    enis.push_back(new Eni( 2000,1700));
    enis.push_back(new Eni( 1700,1650));
    enis.push_back(new Eni( 2100,2050));
    enis.push_back(new Eni( 1900,1500));
    enis.push_back(new Eni(1800 ,1400));
    enis.push_back(new Eni( 2000,1700));
    enis.push_back(new Eni( 1900,1900));
    enis.push_back(new Eni( 1700,2300));
    enis.push_back(new Eni( 1800,2200));
    enis.push_back(new Eni( 2000,2400));
    enis.push_back(new Eni( 1900,2450));

    enis.push_back(new Eni( 2350,1800));
    enis.push_back(new Eni( 2250,1850));
    enis.push_back(new Eni( 2200,1900));
    enis.push_back(new Eni( 2400,2100));
    enis.push_back(new Eni( 2350,2250));

    Boss::load();
    enis.push_back(new Boss(2000,2150));

}

void Level2::unloadEnis()
{
    Boss::unload();
}

void Level2::loadMusic()
{
    musique = Mix_LoadMUS("data/music/53684_newgrounds_milita.mp3");
    if(!musique) {
    std::cerr<<"Mix_LoadMUS: "<< Mix_GetError()<<std::endl;
    // this might be a critical error...
    }
    Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
    Mix_PlayMusic(musique,-1);
}

void Level2::unloadMusic()
{
    Mix_HaltMusic();//stop la musique
    Mix_FreeMusic(musique);
}

void Level2::goNextLevel()
{
    dynamic_cast<MyGame *>(game)->goScene(3);
}
