#ifndef WROBEL_MOST_H
#define WROBEL_MOST_H


#include "Przeszkoda.h"
#include "wrobel_kolec.h"

class most : public Przeszkoda
{
    prostokat wejscie_L, wejscie_P;
    prostokat podest_L, podest_P;
    std::vector<kolec> kolce;
    float m_dlugosc, m_wysokosc;
    prostokat aktywator;
    prostokat przejscie1, przejscie2;
public:
    most(float x, float y, kolor k, bool aktywny, float dlugosc, float wysokosc)
        : Przeszkoda(x, y, k, aktywny), m_dlugosc(dlugosc), m_wysokosc(wysokosc),
        wejscie_L(x - dlugosc / 2.0, y, k, dlugosc / 6.0, wysokosc),
        wejscie_P(x + dlugosc / 2.0, y + wysokosc/2.0, k, dlugosc / 6.0, 2*wysokosc),
        podest_L(x - dlugosc / 3.0, y + wysokosc / 2.0 - wysokosc/12.0, k, dlugosc / 4.0, wysokosc / 6.0),
        podest_P(x + dlugosc / 3.0, y + wysokosc +3, k, dlugosc / 4.0, wysokosc / 6.0),
        przejscie1(x, y + wysokosc / 1.4, k, dlugosc/4.0, wysokosc / 6.0),
        przejscie2(x + dlugosc/6.0,y + wysokosc - 2, k , dlugosc/4.0,wysokosc/6.0),

        aktywator(x + dlugosc / 3.0, y + wysokosc*1.5 , kolor(1, 0, 0), 4, 2)
    {
        elementy.push_back(&wejscie_L);
        elementy.push_back(&wejscie_P);
        elementy.push_back(&podest_L);
        elementy.push_back(&podest_P);

        for (int i = 0; i < dlugosc/2.0; i += 2)
        {
            kolec k(x - dlugosc/4.0 + i , y , kolor(0,0,0), aktywny, 2, 4);
            kolce.push_back(k);
        }
    }

    void collision(Fizyka &obiekt) {}
    void collision_gracz(gracz &g);
    void action() {}
    void rysuj();

};


//most test_6(0, -8, kolor(0, 0, 1), true, 50, 20);
#endif // WROBEL_MOST_H
