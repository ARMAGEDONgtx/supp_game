#ifndef PAWLAK_WINDA_H
#define PAWLAK_WINDA_H


#include "Przeszkoda.h"
#include "figury.h"
#include "figura.h"

class Pawlak_winda : public Przeszkoda
{
    prostokat aktywator_1, aktywator_2;
    prostokat /*sciana*/ winda;
    bool akt = false;
    float m_dlugosc, m_wysokosc;

public:
    Pawlak_winda(float x, float y, kolor k, bool active, float dlugosc, float wysokosc)
        :Przeszkoda(x, y, k, active), m_dlugosc(dlugosc), m_wysokosc(wysokosc),

        aktywator_1(prostokat(m_x - 8, m_y, kolor(1, 1, 1), m_dlugosc*0.7, m_wysokosc)),
        aktywator_2(prostokat(m_x + 8, -3.5, kolor(1, 1, 1), m_dlugosc*0.7, m_wysokosc)),
        //sciana(prostokat(m_x + m_dlugosc + 2, m_y + 6, kolor(1, 1, 1), m_dlugosc * 2, 11)),
        winda(prostokat(m_x, m_y, kolor(1, 1, 1), m_dlugosc, m_wysokosc))
    {

        aktywator_1 = prostokat(m_x - 8, m_y, kolor(1, 1, 1), m_dlugosc*0.7, m_wysokosc);
        aktywator_2 = prostokat(m_x + 8, -3.5, kolor(1, 1, 1), m_dlugosc*0.7, m_wysokosc);
        //sciana=prostokat(m_x + m_dlugosc+2, m_y+6, kolor(1, 1, 1), m_dlugosc*2, 11);
        winda = prostokat(m_x, m_y, kolor(1, 1, 1), m_dlugosc, m_wysokosc);
        elementy.push_back(&aktywator_1);
        elementy.push_back(&aktywator_2);
        //elementy.push_back(&sciana);
        elementy.push_back(&winda);
        UstawGeometrie(x, y, -m_dlugosc / 2.0, -m_wysokosc / 2.0, m_dlugosc / 2.0, m_wysokosc / 2.0);
    }
    void rysuj();
    //void ruch();
    //void collision(Fizyka &obiekt);
    void collision_gracz(gracz &g);
    void action();

};

#endif // PAWLAK_WINDA_H
