#ifndef PAWLAK_WIEZE_H
#define PAWLAK_WIEZE_H


#include "Przeszkoda.h"
#include <vector>
#include "wrobel_kolec.h"
using namespace std;

class Pawlak_wieze : public Przeszkoda
{
    float p_dlugosc, p_wysokosc, k_podstawa, k_wysokosc;
    float m_przerwa;
    prostokat wieza_1, wieza_2, wieza_3, wieza_4;
    vector<kolec> kolce;

public:
    Pawlak_wieze(float x, float y, kolor k, bool active, float dlugosc, float wysokosc, float kpodstawa, float kwysokosc)
        : Przeszkoda(x, y, k, active), p_dlugosc(dlugosc), p_wysokosc(wysokosc),
        k_podstawa(kpodstawa), k_wysokosc(kwysokosc), m_przerwa(10),
        wieza_1(prostokat(x - 3 * m_przerwa, y, kolor(1, 1, 1), dlugosc, wysokosc)),
        wieza_2(prostokat(x - m_przerwa, y+0.5, kolor(1, 1, 1), dlugosc, wysokosc+1)),
        wieza_3(prostokat(x + m_przerwa, y+1, kolor(1, 1, 1), dlugosc, wysokosc+2)),
        wieza_4(prostokat(x + 3 * m_przerwa, y+3.5, kolor(1, 1, 1), dlugosc, wysokosc+7))
    {

        elementy.push_back(&wieza_1);
        elementy.push_back(&wieza_2);
        elementy.push_back(&wieza_3);
        elementy.push_back(&wieza_4);
        for (float i = (x-9.6*m_przerwa);i < (x-6.8*m_przerwa); i+=0.5*kpodstawa)
        {
            kolec t(i,kwysokosc*0.5-2.3, kolor(0, 0, 0), true, kpodstawa, kwysokosc);
            kolce.push_back(t);
            //elementy.push_back(&t);
        }

    }
    void rysuj();
    //void ruch();
    //void collision(Fizyka &obiekt);
    void collision_gracz(gracz &g);
    //void action();
};
#endif // PAWLAK_WIEZE_H
