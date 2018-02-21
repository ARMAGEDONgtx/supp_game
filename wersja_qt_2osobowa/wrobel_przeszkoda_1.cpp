#include "wrobel_przeszkoda_1.h"
#include <iostream>
void up_n_down::loadtextures()
{
    gora.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\metallic.jpg", 5);
    bok1.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\metallic.jpg", 5);
    bok2.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\metallic.jpg", 5);
}
void up_n_down::rysuj()
{


    gora.set_position(m_x, m_y + m_wysokosc / 2.0);
    bok1.set_position(m_x - m_dlugosc / 3.0, m_y - m_wysokosc / 2.0);
    bok2.set_position(m_x + m_dlugosc / 3.0, m_y - m_wysokosc / 2.0);
    gora.rysuj();
    bok1.rysuj();
    bok2.rysuj();


    Aktualizuj(GetTickCount());
    Reset();
}

void up_n_down::ruch()
{


    if (m_y > granica_gora)
    {
        UstawPredkosc(20, -90);
    }
    else if (m_y > neutral - 0.5 && m_y < neutral + 0.5)
    {
        UstawPredkosc(20, 90);
    }
}

void up_n_down::collision_gracz(gracz & g)
{
    for (int i = 0; i < elementy.size(); i++)
    {
        if (elementy[i]->Kolizja(g))
        {
            g.get_dmg();
        }
    }
}

