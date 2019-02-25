#ifndef SCREENMESSAGE_H
#define SCREENMESSAGE_H

#include "../core/Scene.h"
#include "../constante.h"

class ScreenMessage : public Scene
{
    public:
        ScreenMessage(Scene* parent);
        virtual ~ScreenMessage();
        virtual void draw();

        static void loach(const char * text,Scene* parent);

    protected:
        virtual void load();
        virtual void unload();
        virtual void update(int dt);
    private:
        void setText(const char* text);
        char* m_text;

        int delay;
        int delayInit;
};

#endif // SCREENMESSAGE_H
