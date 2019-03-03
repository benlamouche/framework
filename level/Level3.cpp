#include "Level3.h"
#include <iostream>
#include "../Player.h"
#include "../MyGame.h"
extern Player player;

Level3::Level3(): FinalMap("data/map/Level3.mp","data/map/wmap.png")
{
    //ctor
}

Level3::~Level3()
{
    //dtor
}

void Level3::initPlayer()
{
    player.init(870,400);
}

void Level3::initEni()
{
    //montagne
    Eni::vec.push_back(Eni( 350,900));
    Eni::vec.push_back(Eni( 200,900));
    Eni::vec.push_back(Eni( 200,800));
    Eni::vec.push_back(Eni( 200,700));
    Eni::vec.push_back(Eni( 200,600));
    Eni::vec.push_back(Eni( 200,500));
    //iles 1
    Eni::vec.push_back(Eni( 1570,350));
    Eni::vec.push_back(Eni( 1570,450));
    Eni::vec.push_back(Eni( 1640,500));
    Eni::vec.push_back(Eni( 1740,540));
    //iles 2
    Eni::vec.push_back(Eni( 2010,450));
    Eni::vec.push_back(Eni( 2160,600));
    Eni::vec.push_back(Eni( 2280,600));
    Eni::vec.push_back(Eni( 2300,450));
    Eni::vec.push_back(Eni( 2400,530));
    Eni::vec.push_back(Eni( 2400,80));
    Eni::vec.push_back(Eni( 2550,80));
    Eni::vec.push_back(Eni( 2700,80));
    //foret 1
    Eni::vec.push_back(Eni( 1750,850));
    Eni::vec.push_back(Eni( 1650,850));
    Eni::vec.push_back(Eni( 1500,1000));
    Eni::vec.push_back(Eni( 1400,1000));
    Eni::vec.push_back(Eni( 1300,1000));
    Eni::vec.push_back(Eni( 1000,1000));
    Eni::vec.push_back(Eni( 1000,1200));
    Eni::vec.push_back(Eni( 1400,1200));
    Eni::vec.push_back(Eni( 1500,1200));
    Eni::vec.push_back(Eni( 1700,1200));
    Eni::vec.push_back(Eni( 1800,1350));
    Eni::vec.push_back(Eni( 2000,1350));
    Eni::vec.push_back(Eni( 2200,1200));
    Eni::vec.push_back(Eni( 2140,900));
    //foret 2
    Eni::vec.push_back(Eni( 3000,500));
    Eni::vec.push_back(Eni( 3000,700));
    Eni::vec.push_back(Eni( 2850,800));
    Eni::vec.push_back(Eni( 3050,800));
    Eni::vec.push_back(Eni( 2740,900));
    Eni::vec.push_back(Eni( 3100,900));
    Eni::vec.push_back(Eni( 2670,1340));
    //desert 1
    Eni::vec.push_back(Eni( 2350,2000));
    Eni::vec.push_back(Eni( 2550,1900));
    Eni::vec.push_back(Eni( 2650,1900));
    Eni::vec.push_back(Eni( 2750,1900));
    Eni::vec.push_back(Eni( 2850,1900));

    Eni::vec.push_back(Eni( 2150,1900));
    Eni::vec.push_back(Eni( 2200,2150));
    Eni::vec.push_back(Eni( 2000,2350));
    Eni::vec.push_back(Eni( 1900,2700));
    Eni::vec.push_back(Eni( 1900,3000));

    Eni::vec.push_back(Eni( 3050,2260));
    Eni::vec.push_back(Eni( 2800,2330));
    Eni::vec.push_back(Eni( 2500,2430));
    Eni::vec.push_back(Eni( 2400,2600));
    Eni::vec.push_back(Eni( 2500,2800));
    Eni::vec.push_back(Eni( 2600,2800));
    Eni::vec.push_back(Eni( 2700,2800));
    Eni::vec.push_back(Eni( 2900,2900));

    //desert 2
    Eni::vec.push_back(Eni( 900,1900));
    Eni::vec.push_back(Eni( 1350,2300));
    Eni::vec.push_back(Eni( 1400,2450));
    Eni::vec.push_back(Eni( 1200,2450));
    Eni::vec.push_back(Eni( 1000,2450));
    Eni::vec.push_back(Eni( 900,2400));
    Eni::vec.push_back(Eni( 550,2450));
    Eni::vec.push_back(Eni( 400,2300));
    Eni::vec.push_back(Eni( 150,2300));
    Eni::vec.push_back(Eni( 550,2600));
    Eni::vec.push_back(Eni( 800,2700));
    Eni::vec.push_back(Eni( 1000,2600));
    Eni::vec.push_back(Eni( 950,2300));
    Eni::vec.push_back(Eni( 500,3050));
    //iles 3
    Eni::vec.push_back(Eni( 2000,1650));
    Eni::vec.push_back(Eni( 2200,1600));
    Eni::vec.push_back(Eni( 2400,1600));
    //iles 4
    Eni::vec.push_back(Eni( 1500,1900));
    Eni::vec.push_back(Eni( 1700,1900));
    Eni::vec.push_back(Eni( 1100,1500));
    Eni::vec.push_back(Eni( 1250,1600));
    //iles desert
    Eni::vec.push_back(Eni( 1500,2900));
    Eni::vec.push_back(Eni( 1500,3050));

}

void Level3::loadMusic()
{
    musique = Mix_LoadMUS("data/music/770934_Epic-Idea-1.mp3");
    if(!musique) {
    std::cerr<<"Mix_LoadMUS: "<< Mix_GetError()<<std::endl;
    // this might be a critical error...
    }
    Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
    Mix_PlayMusic(musique,-1);
}

void Level3::unloadMusic()
{
    Mix_HaltMusic();//stop la musique
    Mix_FreeMusic(musique);
}

void Level3::goNextLevel()
{
    dynamic_cast<MyGame *>(game)->goScene(0);
}
