#ifndef BIELAN_PRZESZKODA_1_H
#define BIELAN_PRZESZKODA_1_H


#include"Przeszkoda.h"
#include"figury.h"
#include<vector>

class Przeszkoda_Bielan_1 :public Przeszkoda
{
    float kat = 90;
    int abc = 1;
    int i = 180;
    prostokat aktywator_1;
    prostokat aktywator_2;
    belka wahadlo;
    kolo kula;
    std:: vector<kolo>kulki;

public:
    Przeszkoda_Bielan_1(float x, float y, kolor k, bool aktywna) :
        Przeszkoda(x, y, k, aktywna),
        wahadlo(belka(x, y + 10, kolor(1, 1, 1), 0.5, 10.0)),
        aktywator_1(prostokat(x - 15, y-1, kolor(1, 1, 1), 2, 1)),
        aktywator_2(prostokat(x + 15, y-1, kolor(1, 1, 1), 2, 1)),
        kula(kolo(x, y + 10, kolor(1, 0, 1), 1))
    {
        elementy.push_back(&wahadlo);
        elementy.push_back(&aktywator_1);
        elementy.push_back(&aktywator_2);
        for (int i = 0; i < 3; i++)
        {
            kulki.push_back(kolo(x, y + 10, kolor(1, 0, 1), 0.7));
        }
        kulki.push_back(kula);
        //kula.move(0, -10);
    }
    friend void loop();
    void collision(gracz &gracz_1, gracz &gracz_2);
    void action();
    void rysuj();









};


#endif // BIELAN_PRZESZKODA_1_H
