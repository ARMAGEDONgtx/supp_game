#include "wrobel_dzialo.h"

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
	if (this->Kolizja(obiekt))
	{
		m_aktywna = 0;
	}

	if (m_aktywna)
	{
		kontrolka = kolo(m_x, m_y + 2.5, kolor(0, 1, 0), 0.2);
	}
	else kontrolka = kolo(m_x, m_y + 2.5, kolor(1, 0, 0), 0.2);
	
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
