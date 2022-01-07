#include "FinalMap.h"
#include <iostream>
#include "../core/Game.h"
#include "../util/collision.h"
#include "../util/benrandom.h"
#include "../constante.h"
#include "../gfx/SDL2_rotozoom.h"
#include "../Player.h"
#include "../Scene/MenuScene.h"
#include "../MapElement/Plan.h"
#include "../MapElement/Wall.h"
#include "../MapElement/Sortie.h"
#include "../Bullet.h"
#include "../Explosion.h"
#include "../Scene/ScreenMessage.h"
// pour gameOver
#include "../MyGame.h"
using namespace std;
extern Game* game;
//  position du hero sur la map(pas sur l'ecran)
extern Player player;

FinalMap::FinalMap(const char* file,const char* TileSet,int Zoom): Map(file),zoom(Zoom)
{
    //chargement du tileset et mise a l'echelle
        tileSet = IMG_Load(TileSet);
        SDL_Surface *temp = zoomSurface(tileSet,zoom,zoom,SMOOTHING_OFF);
        SDL_FreeSurface(tileSet);
        tileSet = temp;
        m_tileWidth = tileWidth()*zoom;
        m_tileHeight = tileHeight()*zoom;
    //calcul du nombre de tuile pas �cran (�cran doit etre initilis�)
        nbtuecranx=WECRAN/tileWidth();
        nbtuecrany=HECRAN/tileHeight();
    // valeur par default des objet tuile
        MapElement* tempEl = new Plan;
        for(int i=0;i<100;i++){mapElement[i]=tempEl;}
    // ajout des mur
        addElement(new Wall,0);
}

FinalMap::~FinalMap()
{
    SDL_FreeSurface(tileSet);
}

void FinalMap::load()
{
    SDL_SetWindowGrab(ecran,SDL_TRUE);

    menu=0;
    action=0;
    WW =tileSet->w/tileWidth();

    loadEnis();//position Eni + boss
    initPlayer();//position Player

    Bullet::load();
    Explosion::load();
    Eni::load();
    player.load();//pour le son
    loadMusic();
    void setrand();
    std::cerr<<"load map"<<std::endl;
    std::cerr<<"tileWidth : "<< tileWidth() <<" tileHeight : "<< tileHeight() <<std::endl;
}

void FinalMap::unload()
{
    SDL_SetWindowGrab(ecran,SDL_FALSE);
    //vidage des vecteur
    Explosion::vec.clear();
    Explosion::unload();
    Bullet::vec.clear();

    unloadEnis();//boss

    Eni::unload();
    Bullet::unload();
    player.unload();//pour le son
    unloadMusic();

    if(!enis.empty())
        {
            for(eniIt=enis.begin();eniIt!=enis.end();eniIt++){
                delete *eniIt;
            }
        }
        enis.clear();
    std::cerr<<"unload map"<<std::endl;
}

void FinalMap::input()
{
    switch(event.type)
        {
            case SDL_QUIT:
                game->quit();
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)//  Gestion des touches du clavier
                {
                    case SDLK_ESCAPE:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        menu=1;
                        break;
                    case SDLK_RIGHT:
                    case SDLK_d:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        player.goEast();
                        break;
                    case SDLK_LEFT:
                    case SDLK_q:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        player.goWest();
                        break;
                    case SDLK_UP:
                    case SDLK_z:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        player.goNorth();
                        break;
                    case SDLK_DOWN:
                    case SDLK_s:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        player.goSouth();
                        break;
                    case SDLK_RETURN:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche

                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym)//  Gestion des touches du clavier
                {
                    case SDLK_RIGHT:
                    case SDLK_d:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        player.stopEast();
                        break;
                    case SDLK_LEFT:
                    case SDLK_q:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        player.stopWest();
                        break;
                    case SDLK_UP:
                    case SDLK_z:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        player.stopNorth();
                        break;
                    case SDLK_DOWN:
                    case SDLK_s:
                        event.key.keysym.sym=0;//evite les pb de repetition de touche
                        player.stopSouth();
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN  :
                switch(event.button.button)//  Gestion des bouton souris
                {
                    case SDL_BUTTON_LEFT:
                        event.button.button=0;
                        player.fire();
                        break;
                    default:
                        break;
                }
                break;
                case SDL_MOUSEMOTION:
                    player.setMouse(event.motion.x,event.motion.y);
                break;
        }
}



void FinalMap::update(int dt)
{

        if(menu){
            SDL_SetWindowGrab(ecran,SDL_FALSE);
            MenuScene::loach(this);
            menu=0;
            SDL_SetWindowGrab(ecran,SDL_TRUE);
        }

        /* deplacement si pas d'ocbstacle */
        if(testMoov(player.velX(),player.velY(),player.hitBox())){
            player.moov();

        }


        //sinon test des event tuile de la map
//            for(int i=player.posX()/tileWidth()-1;i<player.posX()/tileWidth()+2;i++){
//                for(int j=player.posY()/tileHeight()-1;j<player.posY()/tileHeight()+2;j++){
//                    if(mapElement[obj(i,j)]->doActionOnEnter() || (mapElement[obj(i,j)]->doActionOnAction() && action)){
//                        hitBoxObstacle.x=i*tileWidth()+SDL_GetWindowSurface(ecran)->w/2-player.posX();
//                        hitBoxObstacle.y=j*tileHeight()+SDL_GetWindowSurface(ecran)->h/2-player.posY();
//                            if(boxCollision(hitBox,hitBoxObstacle)){
//                                    velx=vely=0;
//                                    int test = mapElement[obj(i,j)]->action();
//                                    if (test==RESET) {
//                                        loop=0;
//                                    }else if(test==EXIT_MAP){
//                                        loop=0;
//                                    }
//
//                            }
//                }
//            }
//        }



        if(!Bullet::vec.empty())
        {
            for(Bullet::it=Bullet::vec.begin();Bullet::it!=Bullet::vec.end();Bullet::it++){
                Bullet::it->update(player.posX(),player.posY());

                for(eniIt=enis.begin();eniIt!=enis.end();eniIt++)
                {//gestion des collision tir ennemi
                    if(!(*eniIt)->isDestroyed()&&pointCollision(Bullet::it->GetposX(),Bullet::it->GetposY(),(*eniIt)->hitBox())&&Bullet::it->GetTag()==Bullet::AMI){
                        Bullet::it->del();
                        (*eniIt)->damage();
                    }
                }

                if(pointCollision(Bullet::it->GetposX(),Bullet::it->GetposY(),player.hitBox())&&Bullet::it->GetTag()==Bullet::ENI){
                    Bullet::it->del();
                    player.damage();
                }
            }

            for(Bullet::it=Bullet::vec.end()-1;Bullet::it!=Bullet::vec.begin()-1;Bullet::it--){
                if(Bullet::it->toDelete()){
                    Bullet::vec.erase (Bullet::it);
                }
            }
        }

        if(!Explosion::vec.empty())
        {
            for(Explosion::it=Explosion::vec.begin();Explosion::it!=Explosion::vec.end();Explosion::it++){
                Explosion::it->update(player.posX(),player.posY());
            }

            for(Explosion::it=Explosion::vec.end()-1;Explosion::it!=Explosion::vec.begin()-1;Explosion::it--){
                if(Explosion::it->toDelete()){
                    Explosion::vec.erase (Explosion::it);
                }
            }
        }

        if(!enis.empty())
        {
            for(eniIt=enis.begin();eniIt!=enis.end();eniIt++){
                if((*eniIt)->update(player.posX(),player.posY()))
                {
                    if(testMoov((*eniIt)->velX(),(*eniIt)->velY(),(*eniIt)->hitBox()))
                    {
                        (*eniIt)->moov();
                    }else{
                        (*eniIt)->changeDirection();
                    }
                }
            }

            for(eniIt=enis.end()-1;eniIt!=enis.begin()-1;eniIt--){
                if((*eniIt)->isDestroyed()){
                    delete *eniIt;
                    enis.erase (eniIt);
                    std::cerr<<"supression Eni"<<std::endl;
                }
            }
        }else{
            //si plus d'Eni
            ScreenMessage::loach("STAGE CLEAR",this);
            goNextLevel();
        }


        if (player.getPv()<=0){
            std::cerr<<"0 pv"<<std::endl;
            dynamic_cast<MyGame *>(game)->gameOver();
        }
}

void FinalMap::draw()
{
        /* affichage de la map*/
            for(int i=player.posX()/tileWidth()-nbtuecranx/2-1; i<player.posX()/tileWidth()+nbtuecranx/2+2; i++){// affiche seulement ce qui est a l'ecran
                for(int j=player.posY()/tileHeight()-nbtuecrany/2-1; j<player.posY()/tileHeight()+nbtuecrany/2+2; j++){
 //               for(int i=0;i<width();i++){
 //                       for(int j=0;j<height();j++){
                    if (i>=0&&i< this->width()&&j>=0&&j< this->height()){

                        position.h=tileHeight();
                        source.h=tileHeight();
                        position.w=tileWidth();
                        source.w=tileWidth();

                        position.x=i*tileWidth()+SDL_GetWindowSurface(ecran)->w/2-player.posX();
                        position.y=j*tileHeight()+SDL_GetWindowSurface(ecran)->h/2-player.posY();

                        source.x = tile(i,j)%WW*tileWidth();
                        source.y = tile(i,j)/WW*tileHeight();

                        SDL_BlitSurface(tileSet,&source,SDL_GetWindowSurface(ecran),&position);
                    }
                }
            }

            //affichage ennemie
            for(eniIt=enis.begin();eniIt!=enis.end();eniIt++)
            {
                (*eniIt)->draw(player.posX(),player.posY());
            }

            //affichage sprite hero
            player.affiche();

            //affichage Bullet
            if(!Bullet::vec.empty())
            {
                for(Bullet::it=Bullet::vec.begin();Bullet::it!=Bullet::vec.end();Bullet::it++){
                    Bullet::it->draw(player.posX(),player.posY());
                }
            }

            //affichage explosion
            if(!Explosion::vec.empty())
            {
                for(Explosion::it=Explosion::vec.begin();Explosion::it!=Explosion::vec.end();Explosion::it++){
                    Explosion::it->draw(player.posX(),player.posY());
                }
            }
}

bool FinalMap::testMoov(int velX, int velY,SDL_Rect hitBox)
{
    /*test de collision obstacle */
        SDL_Rect hitBoxTest=hitBox;
        SDL_Rect hitBoxWall;
        hitBoxWall.w=tileWidth();
        hitBoxWall.h=tileHeight();

        hitBoxTest.x+=velX;
        hitBoxTest.y+=velY;
        int test=true;

        for(int i=0;i<width() && test;i++){
            for(int j=0;j<height() && test;j++){
                if(mapElement[obj(i,j)]->isAWall()){
                    hitBoxWall.x=i*tileWidth();
                    hitBoxWall.y=j*tileHeight();
                    if(boxCollision(hitBoxTest,hitBoxWall))
                    {
                        test=false;
                    }
                }
            }
        }

        return test;
}

//
void setTunnel(FinalMap *map1,int obj1,FinalMap* map2,int obj2)
{
    int x1(0),x2(0),y1(0),y2(0);
    for(int i = 0;i<map1->width();i++){
            for(int j = 0;j<map1->height();j++){
                if (map1->obj(i,j)==obj1){
                    x1=i;
                    y1=j;
                }
            }
    }
    for(int i = 0;i<map2->width();i++){
            for(int j = 0;j<map2->height();j++){
                if (map2->obj(i,j)==obj2){
                    x2=i;
                    y2=j;
                }
            }
    }
    y1+=2;
    y2+=2;
    map1->addElement(new Sortie(map2,x2*map2->tileWidth()+map2->tileWidth()/2,y2*map2->tileHeight()),obj1);
    map2->addElement(new Sortie(map1,x1*map1->tileWidth()+map1->tileWidth()/2,y1*map1->tileHeight()),obj2);
}

