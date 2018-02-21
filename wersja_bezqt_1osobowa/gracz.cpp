
#include"gracz.h"


void gracz::ruch(float dx, float dy)
{

	for (int i = 0; i < cialo.size(); i++)
	{
		cialo[i]->move(dx, dy);
	}
	this->move(dx, dy);
}

void gracz::chod(int &arg)
{


	if (pom<50 )
	{
		L_noga.rotate(0, 0, -0.2);
		P_noga.rotate(0, 0, 0.2);
	}
	else
	{
		P_noga.rotate(0, 0, -0.2);
		L_noga.rotate(0, 0, 0.2);
	}
	if (pom == 99)
		pom = -1;
	pom++;

}

void gracz::aktualizuj()
{
	cialo[0]->set_position(m_x, m_y + wysokosc * 0.5);
	korpus.set_position(m_x, m_y);
	L_noga.set_position(m_x - 0.1*szerokosc, m_y - wysokosc * 0.4);
	P_noga.set_position(m_x + 0.1*szerokosc, m_y - wysokosc * 0.4);
	L_reka.set_position(m_x - 0.2 * szerokosc, m_y);
	P_reka.set_position(m_x + 0.2 * szerokosc, m_y);
	glowa.set_position(m_x, m_y + 0.3 * wysokosc);
}

float gracz::zwroc_y_gracza()
{
	return m_y;
}

float gracz::zwroc_wysokosc_gracza()
{
	return wysokosc;
}
