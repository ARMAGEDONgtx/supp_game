#include "wrobel_przepasc.h"
extern float ilosc_klatek;
void przepasc::loadtextures()
{
    wejscie.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\castle.jpg",5);
    zejscie.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\castle.jpg", 5);
    blokada.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\castle.jpg", 5);
    przejscie.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\castle.jpg", 5);
    podest_L.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\castle.jpg", 5);

    winda.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\winda.jpg", 5);

}
void przepasc::collision_gracz(gracz & g)
{
    if (g.Kolizja(wejscie))
    {

        g.zezwolenie_na_skok = true;
        g.czy_moze_prawo = false;

        if (g.wsp_Y() < wejscie.wsp_Y() + wejscie.zwroc_wyskosc_prostokata() - g.zwroc_wysokosc_gracza()-0.5)
        {
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);
        }
        else g.ruch(0, 0.01);


    }
    if (g.Kolizja(zejscie))
    {
        g.Reset();
        g.UstawFizyke(0, 0);
        g.UstawPredkosc(0, 0);

        if (g.wsp_Y() - g.zwroc_wysokosc_gracza()*0.6 - 0.5 > zejscie.wsp_Y() + zejscie.zwroc_wyskosc_prostokata() / 2.0)
        {
            g.zezwolenie_na_skok = true;
        }

        if (g.wsp_x() < zejscie.wsp_x() )
        {
            g.czy_moze_prawo = false;
            g.ruch(-0.1, 0);
        }

        if (g.wsp_x() > zejscie.wsp_x())
        {
            g.czy_moze_lewo = false;
            g.ruch(0.1, 0);
        }
    }

    if (g.Kolizja(podest_L) || (g.Kolizja(przejscie) && !m_aktywna))
    {
        g.ruch(0, 0.001);
        g.Reset();
        g.UstawFizyke(0, 0);
        g.UstawPredkosc(0, 0);

        g.zezwolenie_na_skok = true;
    }

    if (g.Kolizja(przelacznik_dol))
    {
        przesun_w_dol = true;
    }
    if (g.Kolizja(przelacznik_gora))
    {
        przesun_w_gore = true;
    }

    if (g.Kolizja(winda))
    {
        if (winda.wsp_x() < m_x + m_dlugosc / 2.0)
        {
            if (przesun_w_gore)
            {
                winda.move(5 / ilosc_klatek, 10 / ilosc_klatek);
            }
            else if (przesun_w_dol)
            {
                winda.move(5 / ilosc_klatek, -10 / ilosc_klatek);
            }
            else winda.move(5 / ilosc_klatek, 0);
        }

        if (g.wsp_x() < winda.wsp_x() - winda.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_prawo = false;
        }
        else if (g.wsp_x() > winda.wsp_x() + winda.zwroc_dlugosc_prostokata() / 2.0)
        {
            g.czy_moze_lewo = false;
        }
        else
        {
            g.UstawPredkosc(0, 0);
            g.UstawFizyke(0, 0);
            g.UstawPredkosc(0, 0);

            g.set_position(g.wsp_x(), winda.wsp_Y() + g.zwroc_wysokosc_gracza()*0.6 + winda.zwroc_wyskosc_prostokata() / 2.0);
            g.zezwolenie_na_skok = true;
        }


        przesun_w_dol = false;
        przesun_w_gore = false;
    }


    if (g.Kolizja(deaktywator))
    {
        m_aktywna = false;
        deaktywator = prostokat(m_x + m_dlugosc / 2.0 + m_dlugosc / 4.0, m_y - m_wysokosc / 3.0, kolor(0, 1, 0), 2, 2);
    }


    if (g.Kolizja(blokada) && m_aktywna == true)
    {
        g.czy_moze_prawo = false;
        g.get_dmg();
    }

}

void przepasc::rysuj()
{
    for (int i = 0; i < elementy.size(); i++)
    {
        elementy[i]->rysuj();
    }
    if (!m_aktywna)
    {
        przejscie.rysuj();
    }
}

