#pragma once


#include"Przeszkoda.h"
#include"figury.h"
#include<vector>

class Przeszkoda_Bielan_1 :public Przeszkoda
{
	float kat=90;
	int abc=1;
	prostokat aktywator_1;
	prostokat aktywator_2;
	belka wahadlo;

public:
	Przeszkoda_Bielan_1(float x, float y, kolor k, bool aktywna) :
		Przeszkoda(x, y, k, aktywna),
		wahadlo(belka(x, 0, kolor(1, 1, 1), 1, 10)),
		aktywator_1(prostokat(x-10,-10,kolor(1,1,1),1,2)), 
		aktywator_2(prostokat(x + 10, -10, kolor(1, 1, 1), 1, 2))
	{
		elementy.push_back(&wahadlo);
		elementy.push_back(&aktywator_1);
		elementy.push_back(&aktywator_2);
	
	}
	friend void loop();
	void collision(Fizyka &gracz);
	void action() ;
	void rysuj();








};