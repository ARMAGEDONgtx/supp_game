#ifndef CZLOWIEK_H
#define CZLOWIEK_H


#include "figury.h"
#include <vector>



class czlowiek : public figura
{
protected:
    int zycie;
    std::vector<figura*> cialo;
public:
    czlowiek(float x = 0, float y=0, kolor k = kolor(1,1,1))
        : figura(x,y,k) , zycie(100)
    {


    }
    void rysuj();

};

#endif // CZLOWIEK_H
