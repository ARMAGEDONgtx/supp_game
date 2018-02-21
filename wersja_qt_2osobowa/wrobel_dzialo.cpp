#include "wrobel_dzialo.h"

void dzialo::loadtextures()
{
    trzon.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\robot.jpg",5);
    lufa.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\robot.jpg", 5);
}

void dzialo::fire()
{
    if (m_aktywna)
    {
        pociski.push_back(kolo(lufa.wsp_x(), lufa.wsp_Y(), kolor(1, 0, 0), 0.5));

        if (pociski.size() != 0)
        {
            pociski[pociski.size() - 1].UstawPredkosc(30, 180);

        }
        else
        {
            pociski[0].UstawPredkosc(30, 180);
        }
    }


}

void dzialo::collision(Fizyka & obiekt)
{

    if (deaktywator.Kolizja(obiekt))
    {
        m_aktywna = 0;
        UstawGeometrie(m_x, m_y, 0, 0, 0, 0);
    }

    if (m_aktywna)
    {
        kontrolka = kolo(m_x, m_y + m_wysokosc , kolor(0, 1, 0), 0.2);
    }
    else kontrolka = kolo(m_x, m_y + m_wysokosc , kolor(1, 0, 0), 0.2);

}

void dzialo::collision_gracz(gracz &g)
{
    for (int i = 0; i < pociski.size();)
    {
        if (pociski[i].Kolizja(g))
        {
            g.get_dmg();
            pociski.erase(pociski.begin() + i);
        }
        else i++;
    }

    if (m_aktywna)
    {
        if ((g.Kolizja(trzon) || g.Kolizja(lufa)) &&( g.wsp_x() < m_x + 0.5 || g.wsp_Y() < lufa.wsp_Y() + m_wysokosc))
        {
            g.czy_moze_prawo = false;
        }
    }
}


void dzialo::rysuj()
{
    for (int i = 0; i < elementy.size(); i++)
    {
        elementy[i]->rysuj();
    }

        for (int i = 0; i < pociski.size(); i++)
        {
            pociski[i].rysuj();
            pociski[i].Aktualizuj(GetTickCount());
            pociski[i].Reset();
        }
        for (auto itr = pociski.begin(); itr != pociski.end();)
        {
            if (abs(itr->wsp_x() - this->m_x) > 40)
            {
                itr = pociski.erase(itr);
            }
            else
            {
                itr++;
            }
        }

}

