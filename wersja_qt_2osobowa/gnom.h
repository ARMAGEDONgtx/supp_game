#ifndef GNOM_H
#define GNOM_H


#include "Przeszkoda.h"

class Gnom : public Przeszkoda
{
protected:
    int pom, strona;
    float granica_L, granica_P;
    int m_zycie;
    kolo korpus;
    prostokat noga_1, noga_2;
    float size;
public:
    Gnom(float x, float y, kolor k, bool active, float zycie,float rozmiar)
        : Przeszkoda(x, y, k, active), m_zycie(zycie), pom(0), strona(0),size(rozmiar),
        granica_L(x - 5*rozmiar/2.0), granica_P(x + 5*rozmiar/2.0),
        korpus(x, y , k, 1*rozmiar),
        noga_1(x - 0.4*rozmiar, y - 1*rozmiar, k, 0.3*rozmiar, 1.2*rozmiar),
        noga_2(x + 0.4*rozmiar, y - 1*rozmiar, k, 0.3*rozmiar, 1.2*rozmiar)
    {

        elementy.push_back(&korpus);
        elementy.push_back(&noga_1);
        elementy.push_back(&noga_2);
        UstawGeometrie(x, y + 2, -1, 2.2, 1, 1);
    }
    void loadtextures();
    void rysuj();
    void ruch();
    void collision(Fizyka &obiekt);
    void collision_gracz(gracz &g);
    void action();
    void aktu();
    bool czy_aktywna() { return m_aktywna; }
    void ustawgranice(float lewa, float prawa) { granica_L = lewa; granica_P = prawa; }
};
#endif // GNOM_H
