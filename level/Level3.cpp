#include "Level3.h"
#include <iostream>
#include "../Player.h"
#include "../MyGame.h"
extern Player player;

Level3::Level3(): FinalMap("data/map/level3.mp","data/map/wmap.png")
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

void Level3::loadEnis()
{
    //montagne
    enis.push_back(new Eni( 350,900));
    enis.push_back(new Eni( 200,900));
    enis.push_back(new Eni( 200,800));
    enis.push_back(new Eni( 200,700));
    enis.push_back(new Eni( 200,600));
    enis.push_back(new Eni( 200,500));
    //iles 1
    enis.push_back(new Eni( 1570,350));
    enis.push_back(new Eni( 1570,450));
    enis.push_back(new Eni( 1640,500));
    enis.push_back(new Eni( 1740,540));
    //iles 2
    enis.push_back(new Eni( 2010,450));
    enis.push_back(new Eni( 2160,600));
    enis.push_back(new Eni( 2280,600));
    enis.push_back(new Eni( 2300,450));
    enis.push_back(new Eni( 2400,530));
    enis.push_back(new Eni( 2400,80));
    enis.push_back(new Eni( 2550,80));
    enis.push_back(new Eni( 2700,80));
    //foret 1
    enis.push_back(new Eni( 1750,850));
    enis.push_back(new Eni( 1650,850));
    enis.push_back(new Eni( 1500,1000));
    enis.push_back(new Eni( 1400,1000));
    enis.push_back(new Eni( 1300,1000));
    enis.push_back(new Eni( 1000,1000));
    enis.push_back(new Eni( 1000,1200));
    enis.push_back(new Eni( 1400,1200));
    enis.push_back(new Eni( 1500,1200));
    enis.push_back(new Eni( 1700,1200));
    enis.push_back(new Eni( 1800,1350));
    enis.push_back(new Eni( 2000,1350));
    enis.push_back(new Eni( 2200,1200));
    enis.push_back(new Eni( 2140,900));
    //foret 2
    enis.push_back(new Eni( 3000,500));
    enis.push_back(new Eni( 3000,700));
    enis.push_back(new Eni( 2850,800));
    enis.push_back(new Eni( 3050,800));
    enis.push_back(new Eni( 2740,900));
    enis.push_back(new Eni( 3100,900));
    enis.push_back(new Eni( 2670,1340));
    //desert 1
    enis.push_back(new Eni( 2350,2000));
    enis.push_back(new Eni( 2550,1900));
    enis.push_back(new Eni( 2650,1900));
    enis.push_back(new Eni( 2750,1900));
    enis.push_back(new Eni( 2850,1900));

    enis.push_back(new Eni( 2150,1900));
    enis.push_back(new Eni( 2200,2150));
    enis.push_back(new Eni( 2000,2350));
    enis.push_back(new Eni( 1900,2700));
    enis.push_back(new Eni( 1900,3000));

    enis.push_back(new Eni( 3050,2260));
    enis.push_back(new Eni( 2800,2330));
    enis.push_back(new Eni( 2500,2430));
    enis.push_back(new Eni( 2400,2600));
    enis.push_back(new Eni( 2500,2800));
    enis.push_back(new Eni( 2600,2800));
    enis.push_back(new Eni( 2700,2800));
    enis.push_back(new Eni( 2900,2900));

    //desert 2
    enis.push_back(new Eni( 900,1900));
    enis.push_back(new Eni( 1350,2300));
    enis.push_back(new Eni( 1400,2450));
    enis.push_back(new Eni( 1200,2450));
    enis.push_back(new Eni( 1000,2450));
    enis.push_back(new Eni( 900,2400));
    enis.push_back(new Eni( 550,2450));
    enis.push_back(new Eni( 400,2300));
    enis.push_back(new Eni( 150,2300));
    enis.push_back(new Eni( 550,2600));
    enis.push_back(new Eni( 800,2700));
    enis.push_back(new Eni( 1000,2600));
    enis.push_back(new Eni( 950,2300));
    enis.push_back(new Eni( 500,3050));
    //iles 3
    enis.push_back(new Eni( 2000,1650));
    enis.push_back(new Eni( 2200,1600));
    enis.push_back(new Eni( 2400,1600));
    //iles 4
    enis.push_back(new Eni( 1500,1900));
    enis.push_back(new Eni( 1700,1900));
    enis.push_back(new Eni( 1100,1500));
    enis.push_back(new Eni( 1250,1600));
    //iles desert
    enis.push_back(new Eni( 1500,2900));
    enis.push_back(new Eni( 1500,3050));
}

void Level3::unloadEnis()
{

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
    dynamic_cast<MyGame *>(game)->goScene(4);
}
