#include "Level2.h"
#include <iostream>
#include "../Player.h"
#include "../MyGame.h"
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

void Level2::initEni()
{
    //desert 1
    Eni::vec.push_back(Eni( 550,1900));
    Eni::vec.push_back(Eni( 650,1850));
    Eni::vec.push_back(Eni( 750,1900));
    Eni::vec.push_back(Eni( 850,1850));
    Eni::vec.push_back(Eni( 950,1900));
    Eni::vec.push_back(Eni( 1050,1850));
    Eni::vec.push_back(Eni( 1150,1900));
    Eni::vec.push_back(Eni( 1250,1850));

    Eni::vec.push_back(Eni( 550,1700));
    Eni::vec.push_back(Eni( 650,1500));
    Eni::vec.push_back(Eni( 750,1600));
    Eni::vec.push_back(Eni( 850,1750));
    Eni::vec.push_back(Eni( 950,1650));
    Eni::vec.push_back(Eni( 1050,1800));
    Eni::vec.push_back(Eni( 1150,1750));
    Eni::vec.push_back(Eni( 1250,1800));

    Eni::vec.push_back(Eni( 550,1400));
    Eni::vec.push_back(Eni( 650,1400));
    Eni::vec.push_back(Eni( 750,1500));
    Eni::vec.push_back(Eni( 850,1700));
    Eni::vec.push_back(Eni( 950,1300));
    Eni::vec.push_back(Eni( 1050,1700));
    Eni::vec.push_back(Eni( 1150,1500));
    Eni::vec.push_back(Eni( 1250,1300));

    Eni::vec.push_back(Eni( 550,1000));
    Eni::vec.push_back(Eni( 650,1300));
    Eni::vec.push_back(Eni( 750,1000));
    Eni::vec.push_back(Eni( 850,1250));
    Eni::vec.push_back(Eni( 950,900));
    Eni::vec.push_back(Eni( 1050,1250));
    Eni::vec.push_back(Eni( 1150,1100));

    Eni::vec.push_back(Eni( 600,400));
    Eni::vec.push_back(Eni( 700,600));
    Eni::vec.push_back(Eni( 600,650));

    //plaine
    Eni::vec.push_back(Eni( 1200,800));
    Eni::vec.push_back(Eni( 1100,450));
    Eni::vec.push_back(Eni( 1700,1000));
    Eni::vec.push_back(Eni( 1500,900));
    Eni::vec.push_back(Eni( 1300,600));
    Eni::vec.push_back(Eni( 1100,600));
    Eni::vec.push_back(Eni( 1500,650));
    Eni::vec.push_back(Eni( 1400,800));

    Eni::vec.push_back(Eni( 1900,800));
    Eni::vec.push_back(Eni(1800 ,450));
    Eni::vec.push_back(Eni( 2000,1000));
    Eni::vec.push_back(Eni( 1900,900));
    Eni::vec.push_back(Eni( 1700,600));
    Eni::vec.push_back(Eni( 1800,600));
    Eni::vec.push_back(Eni( 2000,650));
    Eni::vec.push_back(Eni( 1900,800));

//desert 2
    Eni::vec.push_back(Eni( 1650,1300));
    Eni::vec.push_back(Eni( 2200,2400));
    Eni::vec.push_back(Eni( 1700,1500));
    Eni::vec.push_back(Eni( 1800,2000));
    Eni::vec.push_back(Eni( 1700,1800));
    Eni::vec.push_back(Eni( 2000,1700));
    Eni::vec.push_back(Eni( 1700,1650));
    Eni::vec.push_back(Eni( 2100,2050));
    Eni::vec.push_back(Eni( 1900,1500));
    Eni::vec.push_back(Eni(1800 ,1400));
    Eni::vec.push_back(Eni( 2000,1700));
    Eni::vec.push_back(Eni( 1900,1900));
    Eni::vec.push_back(Eni( 1700,2300));
    Eni::vec.push_back(Eni( 1800,2200));
    Eni::vec.push_back(Eni( 2000,2400));
    Eni::vec.push_back(Eni( 1900,2450));

    Eni::vec.push_back(Eni( 2350,1800));
    Eni::vec.push_back(Eni( 2250,1850));
    Eni::vec.push_back(Eni( 2200,1900));
    Eni::vec.push_back(Eni( 2400,2100));
    Eni::vec.push_back(Eni( 2350,2250));

}

void Level2::loadMusic()
{
    musique = Mix_LoadMUS("data/music/770934_Epic-Idea-1.mp3");
    if(!musique) {
    std::cerr<<"Mix_LoadMUS: "<< Mix_GetError()<<std::endl;
    // this might be a critical error...
    }
    Mix_VolumeMusic(MIX_MAX_VOLUME / 5);
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
