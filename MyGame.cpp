#include "MyGame.h"

#include <iostream>
#include "constante.h"
#include "util/benrandom.h"
#include "Scene/MenuIntro.h"
#include "core/Game.h"
#include "Player.h"
#include "level/Level1.h"
#include "level/Level2.h"
#include "Scene/ScreenMessage.h"

using namespace std;

//  variables globales

TTF_Font* numberFont=NULL;
TTF_Font* texteFont=NULL;
TTF_Font* menuFont=NULL;

Menu *mPrincipal=NULL;

Player player;

extern SDL_Color NOIR ;//  fonctionTTF.cpp
extern SDL_Color VERT ;

MyGame::MyGame()
{
    //ctor

// ***********  CHARGEMENT FONT **********************************

    numberFont=TTF_OpenFont("data/Fette.ttf",15);
    texteFont=TTF_OpenFont("data/breakaway.ttf",80);
    menuFont=TTF_OpenFont("data/MKStencilsansBlack.ttf",50);

//*********************************** CHARGEMENT SCENE **********************************

    menuIntro= new MenuIntro;
    level1= new Level1;
    level2= new Level2;
    this->setCurrentScene(menuIntro);
}

MyGame::~MyGame()
{
    //dtor
    //  fermeture du programme déchargement des modules et sprites

    TTF_CloseFont(texteFont);
    TTF_CloseFont(menuFont);
    TTF_CloseFont(numberFont);

}

void MyGame::gameOver()
{
    std::cerr<<"Game Over"<<std::endl;
    ScreenMessage::loach("GAME OVER",this->currentScene());
    currentScene()->exit();
    this->setCurrentScene(level1);
}

void MyGame::goScene(int level)
{
    currentScene()->exit();
    switch(level)
        {
            case 1:
                this->setCurrentScene(level1);
                break;
            case 2:
                this->setCurrentScene(level2);
                break;
        }
}
