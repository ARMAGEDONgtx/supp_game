#include "boss.h"
#include <cstdlib>
#include <iostream>
void boss::rysuj()
{
    if (m_aktywna)
    {
        Gnom::rysuj();

        for (int i = 0; i < gnomy.size(); i++)
        {
            gnomy[i].rysuj();
            gnomy[i].action();
        }

    }
    else
    {
        gnomy.clear();
        set_position(m_x, 0);
        UstawFizyke(0, 0);
        UstawPredkosc(0, 0);
    }



}

void boss::collision_gracz(gracz & g)
{

if (g.Kolizja(aktywator) && !m_aktywna)
{
    m_aktywna = true;
}
if (m_aktywna)
{
    Gnom::collision_gracz(g);



    for (int i = 0; i < gnomy.size(); i++)
    {
        gnomy[i].collision_gracz(g);
        if (gnomy[i].czy_aktywna() == false)
        {
            size -= 0.5;
            korpus = kolo(m_x, m_y, _kolor, 1 * size);
            korpus.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\wiesia.jpg", 4);
            noga_1 = prostokat(m_x - 0.4*size, m_y - 1 * size, _kolor, 0.3*size, 1.2*size);
            noga_2 = prostokat(m_x + 0.4*size, m_y - 1 * size, _kolor, 0.3*size, 1.2*size);
            gnomy.erase(gnomy.begin() + i);
            loadtextures();
        }
    }
}
}

void boss::collision(Fizyka & obiekt)
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

        for (int i = 0; i < gnomy.size(); i++)
        {
            gnomy[i].collision(obiekt);
        }

}

void boss::action()
{

    if (m_aktywna && gnomy.size() < 5)
    {
        //Gnom::action();
        Gnom gn(m_x, m_y, kolor(1, 1, 1), true, 1, rand() % 4 + 1);
        gn.UstawPredkosc(rand() % 10 + 20, rand() % 30 + 150 );
        gn.UstawFizyke(20, -90);
        gn.ustawgranice(m_x - 40, m_x - 20);
        gn.loadtextures();
        gnomy.push_back(gn);
    }

}
