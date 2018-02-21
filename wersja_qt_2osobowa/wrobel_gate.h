#ifndef WROBEL_GATE_H
#define WROBEL_GATE_H


#include "Przeszkoda.h"


class gate : public Przeszkoda
{
    prostokat sciana;
    prostokat brama;
    kolo gora;
    prostokat aktywator;
    float m_wysokosc;
    float m_dlugosc;
    bool opened;
public:
    gate(float x, float y, kolor k, float wysokosc, float dlugosc, bool active,bool otwarta)
        : Przeszkoda(x, y, k, active), m_wysokosc(wysokosc), m_dlugosc(dlugosc), opened(otwarta),
        sciana(x,y+20,k,4,30), brama(x,y,k,dlugosc,wysokosc), gora(x,y + wysokosc/2.0,k, dlugosc/2.0), aktywator(x-dlugosc/2.0,y + 1.5*wysokosc,kolor(1,0,0),2,4)
    {
        UstawGeometrie(m_x, m_y, -dlugosc / 2.0, -wysokosc / 2.0, dlugosc / 2.0, wysokosc / 2.0);
    }
    void loadtextures();
    void collision(Fizyka &obiekt) {}
    void collision_gracz(gracz &g);
    void action(){}
    void rysuj();

};
#endif // WROBEL_GATE_H
