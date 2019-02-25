#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
using namespace std;

class Explosion
{
    public:
        Explosion(int x, int y);
        virtual ~Explosion();

        int GetposX() { return posX; }
        void SetposX(int val) { posX = val; }
        int GetposY() { return posY; }
        void SetposY(int val) { posY = val; }

        bool toDelete() { return m_toDelete; }
        void del(){m_toDelete=true;}

        void update(int playerX,int playerY);
        void draw(int playerX,int playerY);

        static vector<Explosion> vec;
        static vector<Explosion>::iterator it;

        static void load();
        static void unload();

    protected:

    private:
        static SDL_Surface *sprite;
        int posX;
        int posY;

        int state;

        bool m_toDelete;

};

#endif // EXPLOSION_H
