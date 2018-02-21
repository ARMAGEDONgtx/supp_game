#ifndef WROBEL_PRZEPASC_H
#define WROBEL_PRZEPASC_H


#include "Przeszkoda.h"


class przepasc : Przeszkoda
{
    prostokat wejscie, zejscie, podest_L, przejscie, winda, przelacznik_gora, przelacznik_dol, deaktywator, blokada;

    bool kolizja_z_blokada;
    bool przesun_w_gore, przesun_w_dol;
    float m_dlugosc, m_wysokosc;
public:
    przepasc(float x, float y, kolor k, bool aktywny, float dlugosc, float wysokosc)
        : Przeszkoda(x, y, k, aktywny), kolizja_z_blokada(false), przesun_w_dol(false), przesun_w_gore(false), m_dlugosc(dlugosc), m_wysokosc(wysokosc),
        wejscie(x - dlugosc / 2.0, y, k, dlugosc / 6.0, wysokosc),
        zejscie(x + dlugosc / 2.0, y, k, dlugosc / 6.0, wysokosc),
        podest_L(x - dlugosc / 3.0, y + wysokosc / 2.0 - wysokosc / 12.0, k, dlugosc / 4.0, wysokosc / 6.0),
        przejscie(x, y+wysokosc/2.0 - wysokosc / 12.0, k, dlugosc, wysokosc / 6.0),
        winda(x - dlugosc / 3.0 + dlugosc / 4.0, y + wysokosc / 2.0, k, dlugosc / 12.0, wysokosc / 12.0),
        przelacznik_dol(x - dlugosc / 3.0 + dlugosc / 12.0, y + wysokosc / 2.0, kolor(1, 0, 0), 2,2),
        przelacznik_gora(x - dlugosc / 3.0, y + wysokosc / 2.0, kolor(0, 1, 0), 2, 2),
        deaktywator(x + dlugosc / 2.0 + dlugosc / 4.0, y - wysokosc / 3.0, kolor(1, 0, 0), 2, 2),
        blokada(x + dlugosc/5.0,y + wysokosc/2.0,k,dlugosc/20.0,wysokosc)
    {
        elementy.push_back(&wejscie);
        elementy.push_back(&zejscie);
        elementy.push_back(&podest_L);
        elementy.push_back(&winda);
        elementy.push_back(&przelacznik_dol);
        elementy.push_back(&przelacznik_gora);
        elementy.push_back(&deaktywator);
        elementy.push_back(&blokada);
    }

    void loadtextures();
    void collision(Fizyka &obiekt) {}
    void collision_gracz(gracz &g);
    void action() {}
    void change_activity(bool activity) { m_aktywna = activity; }
    void rysuj();




};
#endif // WROBEL_PRZEPASC_H
