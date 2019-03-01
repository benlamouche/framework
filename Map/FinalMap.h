#ifndef FINALMAP_H
#define FINALMAP_H

#include "Map.h"
#include "../core/Scene.h"
#include <SDL.h>
#include <SDL_image.h>

#include "../Eni.h"

class MapElement;

class FinalMap : public Map, public Scene
{
    public:
        FinalMap(const char* file,const char* TileSet,int Zoom=2);
        virtual ~FinalMap();
        void addElement(MapElement* val,int position){mapElement[position]=val;}
        virtual void draw();

    protected:
        virtual void load();
        virtual void unload();
        virtual void input();
        virtual void update(int dt);


    private:
        FinalMap();
        bool testMoov(int velX, int velY,SDL_Rect hitBox);
        SDL_Surface* tileSet;

        int nbtuecranx;//=WECRAN/WTUILE;
        int nbtuecrany;//=HECRAN/HTUILE;

        MapElement* mapElement[100];

        int zoom;

        int menu;
        int action;
        int WW;
        SDL_Rect position,source;

        virtual void loadMusic()=0;
        virtual void unloadMusic()=0;
        virtual void initPlayer()=0;
        virtual void initEni()=0;
        virtual void goNextLevel()=0;
};

void setTunnel(FinalMap *map1,int obj1,FinalMap* map2,int obj2);

#endif // FINALMAP_H
