#ifndef BULLET_H
#define BULLET_H
#include <SDL.h>
#include <vector>
using namespace std;

class Bullet
{
    public:
        enum from {AMI,ENI};
        Bullet(int x, int y, float angle,from fm);
        virtual ~Bullet();

        int GetposX() { return posX; }
        void SetposX(int val) { posX = val; }
        int GetposY() { return posY; }
        void SetposY(int val) { posY = val; }
        int GetvelX() { return velX; }
        void SetvelX(int val) { velX = val; }
        int GetvelY() { return velY; }
        void SetvelY(int val) { velY = val; }

        bool toDelete() { return m_toDelete; }
        void del(){m_toDelete=true;}

        void update(int playerX,int playerY);
        void draw(int playerX,int playerY);

        static vector<Bullet> vec;
        static vector<Bullet>::iterator it;

        static void load();
        static void unload();


    protected:

    private:
        int posX;
        int posY;
        int velX;
        int velY;

        bool m_toDelete;

        static SDL_Surface *m_sprite1;
        static SDL_Surface *m_sprite2;

        from frm;

};

#endif // BULLET_H
