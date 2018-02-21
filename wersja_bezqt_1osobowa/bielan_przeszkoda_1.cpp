

#include"bielan_przeszkoda_1.h"


void Przeszkoda_Bielan_1::collision(Fizyka &gracz)
{
	if (gracz.Kolizja(aktywator_1))
	{
		m_aktywna = 0;
		aktywator_1.change_color(kolor(0,0,1));
	}
	else if (gracz.Kolizja(aktywator_2))
	{
		m_aktywna = 0;
		aktywator_2.change_color(kolor(0, 0, 1));
	}
	else 
	{
		m_aktywna = 1;
		aktywator_1.change_color(kolor(1, 1, 1));
		aktywator_2.change_color(kolor(1, 1, 1));
	}


	if (gracz.Kolizja(wahadlo))
	{
 		gracz.UstawPredkosc(20, float(kat));
	}
	




}



void Przeszkoda_Bielan_1::action()
{
	if (m_aktywna)
	{

		if (kat > 90)
		{
			abc = 1;
		}
		if (kat < -90)
		{
				abc = 2;
		}
			

		
		

		switch (abc)
		{
			case 1: 
			{
				kat -= 0.1;
				wahadlo.set_rotate(0, 0, kat);
			
				break;
			}
			case 2:
			{
				kat += 0.1;
				wahadlo.set_rotate(0, 0, kat);
				break;
			}	
		}
	}
	else
	{
		wahadlo.set_rotate(0, 0, 90);
	}



}

void Przeszkoda_Bielan_1::rysuj()
{
	aktywator_1.rysuj();
	aktywator_2.rysuj();
	wahadlo.rysuj();
	
}
	




