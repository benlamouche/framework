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
    player.init(900,2350);
}

void Level3::initEni()
{
    //desert 1
    Eni::vec.push_back(Eni( 550,1900));
}

void Level3::loadMusic()
{
    musique = Mix_LoadMUS("data/music/770934_Epic-Idea-1.mp3");
    if(!musique) {
    std::cerr<<"Mix_LoadMUS: "<< Mix_GetError()<<std::endl;
    // this might be a critical error...
    }
    Mix_VolumeMusic(MIX_MAX_VOLUME / 5);
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
