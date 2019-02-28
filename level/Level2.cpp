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
    Eni::vec.push_back(Eni(900,2000));
}

void Level2::loadMusic()
{
    musique = Mix_LoadMUS("data/music/298274_Military_Theme.mp3");
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
    dynamic_cast<MyGame *>(game)->goScene(1);
}
