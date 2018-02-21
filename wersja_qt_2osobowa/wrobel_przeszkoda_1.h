#ifndef WROBEL_PRZESZKODA_1_H
#define WROBEL_PRZESZKODA_1_H

#include "Przeszkoda.h"



class up_n_down : public Przeszkoda
{
    prostokat gora, bok1, bok2;
    float granica_gora;
    float neutral;
    float m_dlugosc, m_wysokosc, dl_wciecia, wys_wciecia;
public:
    up_n_down(float x, float y, kolor k, bool active, float dlugosc, float wysokosc, float d_wciecia, float w_wciecia, int czas)
        : Przeszkoda(x, y, k, active), m_dlugosc(dlugosc), m_wysokosc(wysokosc), dl_wciecia(d_wciecia), wys_wciecia(w_wciecia), neutral(y), granica_gora(y + 1.5*wysokosc),

        gora(prostokat(m_x, m_y + m_wysokosc / 2.0, k, m_dlugosc, m_wysokosc)),
        bok1(prostokat(m_x - m_dlugosc / 3.0, m_y - m_wysokosc / 2.0, k, m_dlugosc / 3.0, m_wysokosc)),
        bok2(prostokat(m_x + m_dlugosc / 3.0, m_y - m_wysokosc / 2.0, k, m_dlugosc / 3.0, m_wysokosc))
    {
        gora = prostokat(m_x, m_y + m_wysokosc / 2.0, kolor(1, 1, 1), m_dlugosc, m_wysokosc);
        bok1 = prostokat(m_x - m_dlugosc / 3.0, m_y - m_wysokosc / 2.0, kolor(1, 1, 1), m_dlugosc / 3.0, m_wysokosc);
        bok2 = prostokat(m_x + m_dlugosc / 3.0, m_y - m_wysokosc / 2.0, kolor(1, 1, 1), m_dlugosc / 3.0, m_wysokosc);
        elementy.push_back(&gora);
        elementy.push_back(&bok1);
        elementy.push_back(&bok2);
        UstawGeometrie(x, y, -m_dlugosc / 2.0, -m_wysokosc / 2.0, m_dlugosc / 2.0, m_wysokosc / 2.0);
        //UstawPredkosc(20, 90);
    }
    void loadtextures();
    void rysuj();
    void ruch();
    void collision(Fizyka &obiekt) {}
    void collision_gracz(gracz &g);
    void action() {
        ruch();}
};
#endif // WROBEL_PRZESZKODA_1_H
