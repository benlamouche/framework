#ifndef GOLEVELITEM_H
#define GOLEVELITEM_H

#include "../menu/ElementMenu.h"
#include "../constante.h"


class GoLevel :public ElementMenu
{
    public:
        GoLevel(int level, const char* name);

        virtual ~GoLevel();

        int action(int val=0);



    protected:

    private:
        int m_level;


};

#endif // GOLEVELITEM_H
