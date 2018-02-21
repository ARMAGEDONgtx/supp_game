#include "Gnom.h"
#include<iostream>
using namespace std;
extern float ilosc_klatek;
void Gnom::loadtextures()
{
    korpus.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\shrek.jpg", 5);
}
void Gnom::rysuj()
{
    if (m_aktywna)
    {
        korpus.rysuj();
        noga_1.rysuj();
        noga_2.rysuj();

        /*for (int i = 0; i < elementy.size(); i++)
        {
            elementy[i]->rysuj();
        }*/


        Aktualizuj(GetTickCount());
        aktu();
        Reset();
    }

}

void Gnom::ruch()
{
    pom++;
    if (pom<50)
    {
        noga_1.rotate(0, 0, -0.2);
        noga_2.rotate(0, 0, 0.2);
    }
    else
    {
        noga_2.rotate(0, 0, -0.2);
        noga_1.rotate(0, 0, 0.2);
    }
    if (pom == 99)
        pom = -1;

}

void Gnom::collision(Fizyka & obiekt)
{
    if (noga_1.Kolizja(obiekt) || noga_2.Kolizja(obiekt))
    {
        UstawFizyke(0, 0);
        UstawPredkosc(0, 0);
    }
    else
    {
        UstawFizyke(20, -90);
    }

}

void Gnom::action()
{
    //for (int i = 0; i < elementy.size(); i++)
    {
        if (strona == 0)
        {
            if (korpus.wsp_x() >= granica_L)
            {
                //elementy[i]->move(-1/ilosc_klatek, 0);
                move(-3 / ilosc_klatek, 0);
                strona = 0;
            }
            else
            {
                strona = 1;
            }
        }
        if (strona == 1)
        {
            if (korpus.wsp_x() <= granica_P)
            {
                //elementy[i]->move(1/ilosc_klatek, 0);
                move(3 / ilosc_klatek, 0);
                strona = 1;
            }
            else
            {
                strona = 0;
            }

        }

    }

    ruch();
}

void Gnom::aktu()
{
    korpus.set_position(m_x, m_y);
    noga_1.set_position(m_x - 0.4*size, m_y - 1*size);
    noga_2.set_position(m_x + 0.4*size, m_y - 1*size);
}

void Gnom::collision_gracz(gracz &g)
{
    if (m_aktywna)
    {
        if (g.Kolizja(korpus))
        {
            //(((g.zwroc_y_gracza() - (0.6*(g.zwroc_wysokosc_gracza()))) >= korpus.wsp_Y()+size*1+1) && ((g.zwroc_y_gracza() - (0.6*(g.zwroc_wysokosc_gracza()))) <= korpus.wsp_Y()+size*1-1))
            if (g.wsp_Y() - g.zwroc_wysokosc_gracza()*0.6 > m_y + 0.75*size)
            {
                strona = 3;
                m_aktywna = false;

            }
            else
            {
                g.get_dmg();
                g.move(-1, 1);
                g.UstawFizyke(10, 90);
                g.UstawPredkosc(50, 160);
                g.UstawFizyke(-10, -90);
            }
        }
    }

}
