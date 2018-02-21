#include "figury.h"
#include <cmath>
prostokat::prostokat(float x, float y, kolor k, float dl, float wys)
	: figura(x,y,k) , dlugosc(dl), wysokosc(wys)
{
	UstawGeometrie(x, y, -dl / 2, -wys / 2, dl / 2, wys / 2);
}

void prostokat::rysuj()
{
	if (widoczny&&hide)
	{
		glPushMatrix();
		glColor3f(_kolor.red, _kolor.green, _kolor.blue);
		glTranslatef(m_x, m_y, 0);
		glRotatef(rX, 1, 0, 0);
		glRotatef(rY, 0, 1, 0);
		glRotatef(rZ, 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-dlugosc / 2, wysokosc / 2, 0);
		glVertex3f(-dlugosc / 2, -wysokosc / 2, 0);
		glVertex3f(dlugosc / 2, -wysokosc / 2, 0);
		glVertex3f(dlugosc / 2, wysokosc / 2, 0);
		glEnd();
		glPopMatrix();
	}
}

float prostokat::zwroc_wyskosc_prostokata()
{
	return wysokosc;
}

kolo::kolo(float x, float y, kolor k, float r)
	: figura(x,y,k), promien(r)
{
	UstawGeometrie(x, y, -promien, -promien, promien, promien);
}

void kolo::rysuj()
{
	if (widoczny&&hide)
	{
		glPushMatrix();
		glColor3f(_kolor.red, _kolor.green, _kolor.blue);
		glTranslatef(m_x, m_y, 0);
		glRotatef(rX, 1, 0, 0);
		glRotatef(rY, 0, 1, 0);
		glRotatef(rZ, 0, 0, 1);
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 360; i++)
		{
			glVertex3f(promien*cos(i), promien*sin(i), 0);
		}
		glEnd();
		glPopMatrix();
	}
}


trojkat::trojkat(float x, float y, kolor k, float podst, float wys)
	: figura(x, y, k), podstawa(podst), wysokosc(wys)
{
	UstawGeometrie(x, y, -podst, -wys, podst, wys);
}

void trojkat::rysuj()
{
	if (widoczny&&hide)
	{
		glPushMatrix();
		glColor3f(_kolor.red, _kolor.green, _kolor.blue);
		glTranslatef(m_x, m_y, 0);
		glRotatef(rX, 1, 0, 0);
		glRotatef(rY, 0, 1, 0);
		glRotatef(rZ, 0, 0, 1);
		glBegin(GL_TRIANGLES);
		glVertex3f(m_x, m_y +  wysokosc/2, 0);
		glVertex3f(m_x - podstawa / 2, m_y - wysokosc / 2, 0);
		glVertex3f(m_x + podstawa / 2, m_y - wysokosc / 2, 0);
		glEnd();
		glPopMatrix();
	}
}


belka::belka(float x, float y, kolor k, float dl, float wys)
	: figura(x, y, k), dlugosc(dl), wysokosc(wys)
{
	UstawGeometrie(x, y, -dl / 2, -wys , dl / 2, 0);
}

void belka::rysuj()
{
	if (widoczny&&hide)
	{
		glPushMatrix();
		glColor3f(_kolor.red, _kolor.green, _kolor.blue);
		glTranslatef(m_x, m_y, 0);
		glRotatef(rX, 1, 0, 0);
		glRotatef(rY, 0, 1, 0);
		glRotatef(rZ, 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-dlugosc / 2, 0, 0);
		glVertex3f(-dlugosc / 2, -wysokosc , 0);
		glVertex3f(dlugosc / 2, -wysokosc , 0);
		glVertex3f(dlugosc / 2, 0 , 0);
		glEnd();
		glPopMatrix();
	}
}

float belka::zwroc_wyskosc_belki()
{
	return wysokosc;
}