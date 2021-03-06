#pragma once
#pragma once
typedef struct sGranica
{
	float xa; //minimalna wartosc x
	float ya; //minimalna wartosc y
	float xb; //maskymalna wartosc x
	float yb; //maskymalna wartosc y
} sGranica;/*granice okreslaja lewy gorny naroznik (xa,ya) i prawy dolny (xb,yb) */


class Fizyka
{
protected:
	int m_czas; //czas ostatniej aktualizacji
	sGranica m_granica; //granice obiektu
	float m_x, m_y; //polozenie srodka masy
	float m_v;//predkosc
	float m_alfa_v;//kierunek wektora predkosci w [stopniach]
	float m_g; //grawitacja
	float m_alfa_g;//kierunek wektora grawitacji

public:
	Fizyka();
	~Fizyka();
	void Aktualizuj(int czas_aktualny);//zmienia polozenie obiektu na podstawie aktualnego czasu
	void UstawPredkosc(float _v, float _m_alfa_v); //ustawia poczatkowa predkosc
	void UstawFizyke(float _g, float _m_alfa_g); //ustawia poczatkowe przyspieszenie
	void UstawGeometrie(float _x, float _y, float _xa, float _ya, float _xb, float _yb);
	virtual int Kolizja(const Fizyka& X); //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)
	void Reset(); //resetuje czas

private:
	void Odbicie(float alfa_n); //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
	int WProstokacie(float _x, float _y, const Fizyka& X);//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego prostokąta
	float Odleglosc(float _x, float _y, float _xa, float _ya, float _xb, float _yb);//wyznacza odleglosc od pewnej prostej przechodzacej przez 2 punkty
	virtual float ZnajdzNormalna(const Fizyka& X);//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
};
