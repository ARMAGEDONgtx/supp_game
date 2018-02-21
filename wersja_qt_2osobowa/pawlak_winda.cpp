#include "Pawlak_winda.h"
#include <iostream>
using namespace std;
void Pawlak_winda::rysuj()
{



    for (int i = 0; i < elementy.size(); i++)
    {
        elementy[i]->rysuj();
    }

    Aktualizuj(GetTickCount());
    Reset();
}

void Pawlak_winda::collision_gracz(gracz &g)
{

    if (g.Kolizja(aktywator_1))
    {
        aktywator_1.change_color(kolor(1,0,1));
        akt = true;
    }
    else if (g.Kolizja(aktywator_2))
    {
        aktywator_2.change_color(kolor(1, 0, 1));
        akt = true;
    }


    if (g.Kolizja(winda))
    {
        g.UstawFizyke(0, 0);
        g.UstawPredkosc(0, 0);
        g.set_position(g.wsp_x(), winda.wsp_Y()+4.0);

    }

}
void Pawlak_winda::action()
{
    if (akt)
    {
        if (winda.wsp_Y() <= -3.5)
        {
            winda.move(0, 0.03);
        }


    }
    else if (!akt)
    {
        if (winda.wsp_Y() >= m_y)
        {
            winda.move(0, -0.03);
            aktywator_1.change_color(kolor(1, 1, 1));
            aktywator_2.change_color(kolor(1, 1, 1));
        }

    }
    akt = false;

}
