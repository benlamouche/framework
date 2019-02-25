#ifndef BULLET_H
#define BULLET_H

#include <vector>
using namespace std;

class Bullet
{
    public:
        Bullet(int x, int y, float angle);
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


    protected:

    private:
        int posX;
        int posY;
        int velX;
        int velY;

        bool m_toDelete;

};

#endif // BULLET_H
