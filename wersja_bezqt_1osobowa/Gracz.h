#pragma once
#include"czlowiek.h"

class gracz : public czlowiek
{

	int pom;
	float wysokosc;
	float szerokosc;
	prostokat HP,korpus, L_noga, P_noga, L_reka, P_reka;
	kolo glowa;

public:
	gracz(float x, float y, kolor k, float wys, float szer)
		: czlowiek(x, y, k), wysokosc(wys), szerokosc(szer), pom(0),
		korpus(x, y, k, szer * 0.3, wys * 0.4),
		L_noga(x - 0.1*szer, y - wys * 0.4, k, szer * 0.1, wys * 0.4),
		P_noga(x + 0.1*szer, y - wys * 0.4, k, szer * 0.1, wys * 0.4),
		L_reka(x - 0.2 * szer, y, k, szer * 0.1, wys * 0.4),
		P_reka(x + 0.2 * szer, y, k, szer * 0.1, wys * 0.4),
		glowa(x, y + 0.3 * wys, k, szer*0.3),
		HP(x, y + 1, kolor(0, 1, 0), zycie*0.02, 0.4)
	{

		cialo.push_back(&HP);
		L_reka.rotate(0, 0, -10);
		P_reka.rotate(0, 0, 10);
		cialo.push_back(&korpus);
		cialo.push_back(&L_noga);
		cialo.push_back(&P_noga);
		cialo.push_back(&L_reka);
		cialo.push_back(&P_reka);
		cialo.push_back(&glowa);
		UstawGeometrie(x, y, -szerokosc*0.15, -wysokosc*0.6, szerokosc*0.15, wysokosc*0.6);
	}
	void ruch(float dx, float dy);
	void chod(int &arg);
	//friend void Czy_Kolizja(const gracz*, const prostokat*);
	void get_dmg() { if(zycie >= 50) zycie -= 40; HP = prostokat(m_x, m_y + 1, kolor(0, 1, 0), zycie * 0.02, 0.4); }

	void aktualizuj();
	float zwroc_y_gracza();
	float zwroc_wysokosc_gracza();
	



};
