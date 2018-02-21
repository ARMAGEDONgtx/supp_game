#include "wrobel_przeszkoda_1.h"
#include <iostream>
void up_n_down::rysuj()
{
	gora = prostokat(m_x, m_y + m_wysokosc / 2.0, kolor(1, 1, 1), m_dlugosc, m_wysokosc);
	bok1 = prostokat(m_x - m_dlugosc / 3.0, m_y - m_wysokosc / 2.0, kolor(1, 1, 1), m_dlugosc / 3.0, m_wysokosc);
	bok2 = prostokat(m_x + m_dlugosc / 3.0, m_y - m_wysokosc / 2.0, kolor(1, 1, 1), m_dlugosc / 3.0, m_wysokosc);
	glPushMatrix();
	gora.rysuj();
	bok1.rysuj();
	bok2.rysuj();
	glPopMatrix();

	Aktualizuj(GetTickCount());
	Reset();
}

void up_n_down::ruch()
{


	if (m_y > granica_gora-0.5 && m_y < granica_gora +0.5)
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
