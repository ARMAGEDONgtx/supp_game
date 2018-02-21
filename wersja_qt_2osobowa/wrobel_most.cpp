#include "wrobel_most.h"

void most::collision_gracz(gracz & g)
{
    g.zezwolenie_na_skok = false;
    if (g.Kolizja(wejscie_L))
    {
        g.UstawFizyke(0, 0);
        g.UstawPredkosc(0, 0);
        g.czy_moze_prawo = false;
        g.zezwolenie_na_skok = true;
    }

    if (g.Kolizja(wejscie_P))
    {
        if (g.wsp_x() > wejscie_P.wsp_x() - wejscie_P.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);
            g.czy_moze_lewo = false;
        }
        else g.czy_moze_prawo = false;
    }

    if (g.Kolizja(podest_L) && g.wsp_Y() - g.zwroc_wysokosc_gracza()*0.6 > podest_L.wsp_Y())
    {

        g.UstawFizyke(0, 0);
        g.UstawPredkosc(0, 0);
        g.czy_moze_skok = true;
        g.zezwolenie_na_skok = true;
    }

    if (g.Kolizja(podest_P))
    {
        if (g.wsp_x() > podest_P.wsp_x() - podest_P.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.ruch(0, 0.01);
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);
            g.czy_moze_skok = true;
            g.zezwolenie_na_skok = true;
        }
        else g.czy_moze_prawo = false;
    }
    if ( g.Kolizja(przejscie1) && !m_aktywna)
    {

        if (g.wsp_x() > przejscie1.wsp_x() - przejscie1.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);
            g.czy_moze_skok = true;
            g.zezwolenie_na_skok = true;
        }
        else g.czy_moze_prawo = false;

    }
    if (g.Kolizja(przejscie2) && !m_aktywna)
    {

        if (g.wsp_x() > przejscie2.wsp_x() - przejscie2.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);
            g.czy_moze_skok = true;
            g.zezwolenie_na_skok = true;
        }
        else g.czy_moze_prawo = false;

    }


    //for (int i = 0; i < kolce.size(); i++)
    //{
    //	kolce[i].collision_gracz(g);
    //}



    if (g.Kolizja(aktywator))
    {
        aktywator = prostokat(m_x + m_dlugosc / 3.0, m_y + m_wysokosc*1.5, kolor(0, 1, 0), 4, 2);
        m_aktywna = false;
    }
}

void most::rysuj()
{
    for (int i = 0; i < elementy.size(); i++)
    {
        elementy[i]->rysuj();
    }
    if (!m_aktywna)
    {
        przejscie1.rysuj();
        przejscie2.rysuj();
    }

    for (int i = 0; i < kolce.size(); i++)
    {
        kolce[i].rysuj();
    }

    aktywator.rysuj();
}

