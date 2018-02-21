#pragma once
#include "figura.h"
#include "czlowiek.h"

class prostokat : public figura
{
	float dlugosc, wysokosc;
	static bool hide;


public:
	prostokat(float x, float y, kolor k, float dl, float wys);
	void rysuj();
	static void hide_all() { hide = !hide; };
	//friend void Czy_Kolizja(const gracz*, const prostokat*);
	float zwroc_wyskosc_prostokata();

};

class kolo : public figura
{
	static bool hide ;
	float promien;
public:
	kolo(float x, float y, kolor k, float r);
	void rysuj();
	static void hide_all() { hide = !hide; }
};

class trojkat : public figura
{
	static bool hide;
	float podstawa, wysokosc;
public:
	trojkat(float x, float y, kolor k, float podst, float wys);
	void rysuj();
	static void hide_all() { hide = !hide; }
};


class belka : public figura
{
	float dlugosc, wysokosc;
	static bool hide;


public:
	belka(float x, float y, kolor k, float dl, float wys);
	void rysuj();
	static void hide_all() { hide = !hide; };
	//friend void Czy_Kolizja(const gracz*, const prostokat*);
	float zwroc_wyskosc_belki();

};