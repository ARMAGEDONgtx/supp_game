#ifndef PRZESZKODA_H
#define PRZESZKODA_H


#include "figura.h"
#include "figury.h"
#include <vector>
#include "Gracz.h"

class Przeszkoda : public figura
{
protected:
    bool m_aktywna;
    std::vector<figura*> elementy;

public:
    Przeszkoda(float x, float y, kolor k, bool aktywny)
        : figura(x,y,k), m_aktywna(aktywny) {}

    virtual void collision(Fizyka &obiekt) {}
    virtual void collision_gracz(gracz &g) {}
    virtual void action() {}
    void change_activity(bool activity) { m_aktywna = activity; }
    virtual void rysuj() = 0;


};

#endif // PRZESZKODA_H
