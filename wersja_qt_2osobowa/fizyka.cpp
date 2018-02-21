#include <windows.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include "fizyka.h"
#include <iostream>
using namespace std;

Fizyka::Fizyka()
{
    //obiekt staly
    m_g = 0.0;
    m_alfa_g = 0.0;
    m_v = 0.0;
    m_alfa_v = 0.0;

    m_x = 0;
    m_y = 0;
    //ustawia domyslna obwiednie obiektu
    m_granica.xa = -1.0;
    m_granica.ya = -1.0;

    m_granica.xb = 1.0;
    m_granica.yb = 1.0;
    Reset();
}

Fizyka::~Fizyka()
{
}

void Fizyka::Odbicie(float alfa_n) //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
{
    //prawo odbicia "kat padania rowny katowi odbicia (pod warunkiem, ze obiekt wnika do wnetrza)
    if (fabs(alfa_n - m_alfa_v) > 90.0f)
        m_alfa_v = alfa_n - (180.0f + m_alfa_v - alfa_n);
}

void Fizyka::Aktualizuj(int czas_aktualny) //zmienia polozenie obiektu na podstawie aktualnego czasu
{

    float delta_t = (czas_aktualny - m_czas) / 2500.0;
    float v_x, v_y;

    v_x = m_v*cos(m_alfa_v / 180.0f*M_PI);
    v_y = m_v*sin(m_alfa_v / 180.0f*M_PI);

    m_x = m_x + v_x*delta_t + 0.5f*m_g*cos(m_alfa_g / 180.0f*M_PI)*delta_t*delta_t;
    m_y = m_y + v_y*delta_t + 0.5f*m_g*sin(m_alfa_g / 180.0f*M_PI)*delta_t*delta_t;



    //aktualizacja predkosci
    v_x = v_x + m_g*cos(m_alfa_g / 180.0f*M_PI)*delta_t;
    v_y = v_y + m_g*sin(m_alfa_g / 180.0f*M_PI)*delta_t;
    //wypadkowa predkosc
    m_v = sqrt(v_x*v_x + v_y*v_y);
    //kierunek predkosci
    m_alfa_v = atan2(v_y, v_x)*180.0f / M_PI;

    m_czas += delta_t;
}

void Fizyka::UstawPredkosc(float _v, float _m_alfa_v) //ustawia poczatkowa predkosc
{
    m_v = _v;
    m_alfa_v = _m_alfa_v;
    Reset();
}

void Fizyka::UstawFizyke(float _g, float _m_alfa_g) //ustawia poczatkowe przyspieszenie
{
    m_g = _g;
    m_alfa_g = _m_alfa_g;
    //Reset();
}

void Fizyka::UstawGeometrie(float _x, float _y, float _xa, float _ya, float _xb, float _yb)
{
    m_x = _x;
    m_y = _y;
    m_granica.xa = _xa;
    m_granica.xb = _xb;
    m_granica.ya = _ya;
    m_granica.yb = _yb;
    Reset();
}

int Fizyka::Kolizja(const Fizyka& X) //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)
{
    //jesli wystepuje kolizja to przynajmniej jeden z wierzcholkow musi zawierac sie wewnatrz
    //sprawdzenie czy ktorys z wierzcholkow obiektu nie zawiera sie w obiekcie sprawdzanym
    int kolizja = 0;
    if (WProstokacie(m_x + m_granica.xa, m_y + m_granica.ya, X) == 1) kolizja = 1;
    else if (WProstokacie(m_x + m_granica.xa, m_y + m_granica.yb, X) == 1) kolizja = 1;
    else if (WProstokacie(m_x + m_granica.xb, m_y + m_granica.yb, X) == 1) kolizja = 1;
    else if (WProstokacie(m_x + m_granica.xb, m_y + m_granica.ya, X) == 1) kolizja = 1;
    //odworcenie sprawdzania
    else if (WProstokacie(X.m_x + X.m_granica.xa, X.m_y + X.m_granica.ya, *this) == 1) kolizja = 1;
    else if (WProstokacie(X.m_x + X.m_granica.xa, X.m_y + X.m_granica.yb, *this) == 1) kolizja = 1;
    else if (WProstokacie(X.m_x + X.m_granica.xb, X.m_y + X.m_granica.yb, *this) == 1) kolizja = 1;
    else if (WProstokacie(X.m_x + X.m_granica.xb, X.m_y + X.m_granica.ya, *this) == 1) kolizja = 1;

    //obsluga kolizji
    if (kolizja)
    {
        //znalezienie boku od ktorego nastapi odbicie
        float alfa_n = ZnajdzNormalna(X);
        //UstawFizyke(0, 0);
        //Odbicie(alfa_n);
    }

    return kolizja;
}

int Fizyka::WProstokacie(float _x, float _y, const Fizyka& X)//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego kwadratu
{
    if (((_x < X.m_x + X.m_granica.xb) && (_x > X.m_x + X.m_granica.xa)) && ((_y < X.m_y + X.m_granica.yb) && (_y > X.m_y + X.m_granica.ya)))
        return 1;
    else return 0;
}

float Fizyka::Odleglosc(float _x, float _y, float _xa, float _ya, float _xb, float _yb)//wyznacza Odleglosc od pewnej prostej przechodzacej przez 2 punkty
{
    //rownanie prostej pzrechodzacej pzrez 2 punkty: y=Ax+B
    float d;
    if (_xb != _xa)
    {
        float A = (_yb - _ya) / (_xb - _xa);
        float B = _ya - A * _xa;
        //wyznaczenie Odleglosci:
        d = fabs(A*_x - _y + B) / sqrt(A*A + 1.0f);
    }
    else
        d = fabs(_x - _xb);
    return d;
}


float Fizyka::ZnajdzNormalna(const Fizyka& X)//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
{
    float tab[4];//tablica zawierajaca Odleglosci srodka obiektu od bokow, przyjmuje sie ze odbicie nastepuje od boku lezacego najblizej srodka obiektu
    int min_idx = 0;
    tab[0] = Odleglosc(m_x, m_y, X.m_x + X.m_granica.xa, X.m_y + X.m_granica.ya, X.m_x + X.m_granica.xa, X.m_y + X.m_granica.yb);
    tab[1] = Odleglosc(m_x, m_y, X.m_x + X.m_granica.xa, X.m_y + X.m_granica.yb, X.m_x + X.m_granica.xb, X.m_y + X.m_granica.yb);
    tab[2] = Odleglosc(m_x, m_y, X.m_x + X.m_granica.xb, X.m_y + X.m_granica.yb, X.m_x + X.m_granica.xb, X.m_y + X.m_granica.ya);
    tab[3] = Odleglosc(m_x, m_y, X.m_x + X.m_granica.xb, X.m_y + X.m_granica.ya, X.m_x + X.m_granica.xa, X.m_y + X.m_granica.ya);

    //poszukiwanie minimalnej wartosci Odleglosci
    for (int i = 1; i < 4; i++)
        if (tab[i] < tab[min_idx]) min_idx = i;

    //wyznaczenie normalnych najblizej lezacego boku, (dla aktualnej wersji zawsze leza wzdloz osi X lub Y)
    switch (min_idx)
    {
    case 0: return 180.0;
    case 1: return 90.0;
    case 2: return 0.0;
    case 3: return -90.0;
    }
}

void Fizyka::Reset() //resetuje czas
{
    m_czas = GetTickCount();
}
