#ifndef WROBEL_DZIALO_H
#define WROBEL_DZIALO_H


/// WROBEL PRZESZKODAAAAA
// gracze musza sie podsadzic aby przeskoczyc nad wiezyczka, boundry box przesuniety zeby dopireo za wiezyczka mozna bylo ja wylaczyc(KOLIZJA = wylaczenie)

#include "Przeszkoda.h"
#include <cmath>
class dzialo :public Przeszkoda
{
    prostokat trzon, deaktywator;
    kolo lufa;
    kolo kontrolka;
    float m_dlugosc;
    float m_wysokosc;
    std::vector<kolo> pociski;
public:
    dzialo(float x, float y, kolor k, bool aktywna,float dlugosc, float wysokosc) :
        Przeszkoda(x, y, k, aktywna),  m_dlugosc(dlugosc), m_wysokosc(wysokosc),
        trzon(prostokat(x, y, kolor(1, 1, 1),dlugosc,wysokosc)), kontrolka(x, y + wysokosc + dlugosc, kolor(0, 1, 0), 0.2), lufa(kolo(x, y + wysokosc/2.0, kolor(1, 1, 1), dlugosc*0.75)),
        deaktywator(x + dlugosc, y , kolor(0, 0, 0), 1, 2)
    {
        elementy.push_back(&deaktywator);
        elementy.push_back(&kontrolka);
        elementy.push_back(&trzon);
        elementy.push_back(&lufa);
        UstawGeometrie(x, y, -dlugosc / 2.0, -wysokosc / 2.0 + dlugosc*0.75, dlugosc / 2.0, wysokosc / 2.0  + dlugosc*0.75);
    }
    friend void loop();
    void loadtextures();
    void fire();
    void collision(Fizyka &obiekt);
    void collision_gracz(gracz &gracz);
    void rysuj();
    void action() { fire(); }
};
#endif // WROBEL_DZIALO_H
