#pragma once
/// WROBEL PRZESZKODAAAAA
// gracze musza sie podsadzic aby przeskoczyc nad wiezyczka, boundry box przesuniety zeby dopireo za wiezyczka mozna bylo ja wylaczyc(KOLIZJA = wylaczenie)

#include "Przeszkoda.h"
#include <cmath>
class dzialo :public Przeszkoda
{
	prostokat trzon;
	kolo lufa;
	kolo kontrolka;
	int m_size;
	std::vector<kolo> pociski;
public:
	dzialo(float x, float y, kolor k, bool aktywna,int size=1) :
		Przeszkoda(x, y, k, aktywna), trzon(prostokat(x, y, kolor(1, 1, 1), 1, 4)),kontrolka(x,y+2.5,kolor(0,1,0),0.2), lufa(kolo(x, y + 1, kolor(1, 1, 1), 1)), m_size(size)
	{
		elementy.push_back(&kontrolka);
		elementy.push_back(&trzon);
		elementy.push_back(&lufa);
		UstawGeometrie(x, y, -1.5*size, -2 * size, 1.5*size, 2 * size);
	}
	friend void loop();
	void fire();
	void collision(Fizyka &obiekt);
	void collision_gracz(gracz &gracz);
	void rysuj();
	void action() { fire(); }
};