#include "Pawlak_slupki.h"
#include <iostream>
using namespace std;
void Pawlak_slupki::rysuj()
{



    for (int i = 0; i < elementy.size(); i++)
    {
        elementy[i]->rysuj();
    }


    Aktualizuj(GetTickCount());
    Reset();
}
void Pawlak_slupki::collision_gracz(gracz &g)
{

    if (g.Kolizja(aktywator_1))
    {
        aktywator_1.change_color(kolor(1, 0, 1));
        akt = true;
    }
    else if (g.Kolizja(aktywator_2))
    {
        aktywator_2.change_color(kolor(1, 0, 1));
        akt = true;
    }

    if (((g.wsp_x()) >= (slupek_1.wsp_x() - slupek_1.zwroc_wyskosc_prostokata()*0.5))
        && (g.wsp_x() <= slupek_1.wsp_x()))
    {

        if ((ruch) && (cwiartka == 1))
        {

            g.get_dmg();
            g.move(-1, 1);
            g.UstawFizyke(10, 90);
            g.UstawPredkosc(20, 160);
            g.UstawFizyke(-10, -90);
        }
    }
    else if (((g.wsp_x()) <= (slupek_1.wsp_x() + slupek_1.zwroc_wyskosc_prostokata()*0.5))
        && (g.wsp_x() >= slupek_1.wsp_x()))
    {

        if ((ruch) && (cwiartka == 0))
        {

            g.get_dmg();
            g.move(-1, 1);
            g.UstawFizyke(10, 90);
            g.UstawPredkosc(20, 160);
            g.UstawFizyke(-10, -90);
        }
    }

    if (((g.wsp_x()) >= (slupek_2.wsp_x() - slupek_2.zwroc_wyskosc_prostokata()*0.5))
        && (g.wsp_x() <= slupek_2.wsp_x()))
    {

        if ((ruch) && (cwiartka == 0))
        {

            g.get_dmg();
            g.move(-1, 1);
            g.UstawFizyke(10, 90);
            g.UstawPredkosc(20, 160);
            g.UstawFizyke(-10, -90);
        }
    }
    else if (((g.wsp_x()) <= (slupek_2.wsp_x() + slupek_2.zwroc_wyskosc_prostokata()*0.5))
        && (g.wsp_x() >= slupek_2.wsp_x()))
    {

        if ((ruch) && (cwiartka == 1))
        {

            g.get_dmg();
            g.move(-1, 1);
            g.UstawFizyke(10, 90);
            g.UstawPredkosc(20, 160);
            g.UstawFizyke(-10, -90);
        }
    }
    if (slupek_1.Kolizja(g))
    {

        if (ruch)
        {
            g.get_dmg();
            g.move(-1, 1);
            g.UstawFizyke(10, 90);
            g.UstawPredkosc(20, 160);
            g.UstawFizyke(-10, -90);
        }
        else
        {
            if ((g.wsp_x() < slupek_1.wsp_x()) && (kat == 0))
            {
                g.czy_moze_prawo = false;
            }
            if ((g.wsp_x() > slupek_1.wsp_x()) && (kat == 0))
            {
                g.czy_moze_lewo = false;
            }
        }
    }

    if (slupek_2.Kolizja(g))
    {

        if (ruch)
        {
            g.get_dmg();
            g.move(-1, 1);
            g.UstawFizyke(10, 90);
            g.UstawPredkosc(20, 160);
            g.UstawFizyke(-10, -90);
        }
        else
        {
            if ((g.wsp_x() < slupek_2.wsp_x()) && (kat == -90))
            {
                g.czy_moze_prawo = false;
            }
            if ((g.wsp_x() > slupek_2.wsp_x()) && (kat == -90))
            {
                g.czy_moze_lewo = false;
            }
        }
    }



}

void Pawlak_slupki::action()
{

    if (akt)
    {
        if (kat > -90)
        {
            cwiartka = 1;
            ruch = true;
            --kat;
            slupek_1.set_rotate(0, 0, --kat_1);
            slupek_2.set_rotate(0, 0, --kat_2);
        }


    }

    /*if(!akt && kat>-90)
    {



            cwiartka = 1;
            ruch = true;
            --kat;
            slupek_1.set_rotate(0, 0, --kat_1);
            slupek_2.set_rotate(0, 0, --kat_2);

    }*/
    else if (!akt)
    {

        if (kat < 0)
        {
            cwiartka = 0;
            ruch = true;
            ++kat;
            slupek_1.set_rotate(0, 0, --kat_1);
            slupek_2.set_rotate(0, 0, --kat_2);
            aktywator_1.change_color(kolor(1, 1, 1));
            aktywator_2.change_color(kolor(1, 1, 1));
        }

    }
    if ((kat == -90)|| (kat == 0))
    {
        ruch = false;
    }

    akt = false;
}
