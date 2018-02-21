#ifndef WROBEL_KOLEC_H
#define WROBEL_KOLEC_H


#include "Przeszkoda.h"

class kolec : public Przeszkoda
{
    trojkat kol;
    float m_podstawa, m_wysokosc;
public:
    kolec(float x, float y, kolor k, bool aktywny, float podstawa, float wysokosc)
        : Przeszkoda(x,y,k,aktywny), kol(x,y,k,podstawa,wysokosc)
    {
        UstawGeometrie(x, y, -podstawa / 2.0, -wysokosc / 2.0, podstawa / 2.0, wysokosc / 2.0);
    }
    void collision(Fizyka &obiekt) {}
    void collision_gracz(gracz &g);
    void action() {}
    void rysuj();
};
#endif // WROBEL_KOLEC_H
