#include "Pawlak_wieze.h"

void Pawlak_wieze::rysuj()
{
    if (m_aktywna)
    {

        for (int i = 0; i < elementy.size(); i++)
        {
            elementy[i]->rysuj();
        }
        for (int i = 0;i < kolce.size();i++)
        {
            kolce[i].rysuj();
        }

        Aktualizuj(GetTickCount());
        Reset();
    }
}
void Pawlak_wieze::collision_gracz(gracz &g)
{
    if (g.Kolizja(wieza_1))
    {

        if (g.wsp_x() < wieza_1.wsp_x() - wieza_1.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_prawo = false;
        }
        else if (g.wsp_x() > wieza_1.wsp_x() + wieza_1.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_lewo = false;
        }
        else
        {
            g.UstawPredkosc(0, 0);
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);

            g.set_position(g.wsp_x(), wieza_1.wsp_Y() + g.zwroc_wysokosc_gracza()*0.6 + wieza_1.zwroc_wyskosc_prostokata() / 2.0);
            g.zezwolenie_na_skok = true;
        }
    }
    else if (wieza_2.Kolizja(g))
    {
        if (g.wsp_x() < wieza_2.wsp_x() - wieza_2.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_prawo = false;
        }
        else if (g.wsp_x() > wieza_2.wsp_x() + wieza_2.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_lewo = false;
        }
        else
        {
            g.UstawPredkosc(0, 0);
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);

            g.set_position(g.wsp_x(), wieza_2.wsp_Y() + g.zwroc_wysokosc_gracza()*0.6 + wieza_2.zwroc_wyskosc_prostokata() / 2.0);
            g.zezwolenie_na_skok = true;
        }
    }
    else if (wieza_3.Kolizja(g))
    {
        if (g.wsp_x() < wieza_3.wsp_x() - wieza_3.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_prawo = false;
        }
        else if (g.wsp_x() > wieza_3.wsp_x() + wieza_3.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_lewo = false;
        }
        else
        {
            g.UstawPredkosc(0, 0);
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);

            g.set_position(g.wsp_x(), wieza_3.wsp_Y() + g.zwroc_wysokosc_gracza()*0.6 + wieza_3.zwroc_wyskosc_prostokata() / 2.0);
            g.zezwolenie_na_skok = true;
        }
    }
    else if (wieza_4.Kolizja(g))
    {
        if (g.wsp_x() < wieza_4.wsp_x() - wieza_4.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_prawo = false;
        }
        else if (g.wsp_x() > wieza_4.wsp_x() + wieza_4.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_lewo = false;
        }
        else
        {
            g.UstawPredkosc(0, 0);
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);

            g.set_position(g.wsp_x(), wieza_4.wsp_Y() + g.zwroc_wysokosc_gracza()*0.6 + wieza_4.zwroc_wyskosc_prostokata() / 2.0);
            g.zezwolenie_na_skok = true;
        }
    }

    for (int i = 1;i < kolce.size();i++)
    {
        if (g.Kolizja(kolce[i]))
        {
            g.set_position(130, g.zwroc_y_gracza());
            g.get_dmg();

        }
    }
}
