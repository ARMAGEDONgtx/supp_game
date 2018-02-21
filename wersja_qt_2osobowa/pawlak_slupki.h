#ifndef PAWLAK_SLUPKI_H
#define PAWLAK_SLUPKI_H


#include "Przeszkoda.h"

class Pawlak_slupki : public Przeszkoda
{
    float m_dlugosc, m_wysokosc;
    int kat, kat_1, kat_2, cwiartka;
    bool akt, ruch;
    prostokat slupek_1, slupek_2;
    prostokat aktywator_1, aktywator_2;

public:
    Pawlak_slupki(float x, float y, kolor k, bool active, float dlugosc, float wysokosc)
        : Przeszkoda(x, y, k, active), m_dlugosc(dlugosc), m_wysokosc(wysokosc),
        akt(false), kat_1(0), kat_2(-90), kat(0), ruch(false),cwiartka(1),
        aktywator_1(prostokat(x-2*wysokosc,y-1,kolor(1,1,1),14.0/5.0,dlugosc)),
        aktywator_2(prostokat(x + 2 * wysokosc, y-1, kolor(1, 1, 1), 14.0 / 5.0, dlugosc)),
        slupek_1(prostokat(x - wysokosc, y+0.7*wysokosc, kolor(1, 1, 1), dlugosc, wysokosc)),
        slupek_2(prostokat(x + wysokosc, y + 0.7*wysokosc, kolor(1, 1, 1),  dlugosc, wysokosc))
        {

            elementy.push_back(&aktywator_1);
            elementy.push_back(&aktywator_2);
            elementy.push_back(&slupek_1);
            elementy.push_back(&slupek_2);
        }
    void rysuj();
    //void ruch();
    //void collision(Fizyka &obiekt);
    void collision_gracz(gracz &g);
    void action();
};
#endif // PAWLAK_SLUPKI_H
