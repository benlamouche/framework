#ifndef ENDING_H
#define ENDING_H

#include "core/Scene.h"


class Ending : public Scene
{
    public:
        Ending();
        virtual ~Ending();

    protected:
        virtual void load();
        virtual void unload();
        virtual void update(int dt);
        virtual void draw();
    private:

};

#endif // ENDING_H
