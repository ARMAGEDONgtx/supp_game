#include "figura.h"

figura::figura(float x, float y, kolor k)
	: rX(0),rY(0),rZ(0),widoczny(true)
{
	_kolor = k;
	UstawGeometrie(x, y, 1, 1, 1, 1);
}

void figura::set_position(float x, float y)
{
	m_x = x;
	m_y = y;
}

void figura::move(float dx, float dy)
{
	m_x += dx;
	m_y += dy;
}

void figura::change_color(kolor k)
{
	_kolor = k;
}

void figura::rotate(float rotX, float rotY, float rotZ)
{
	rX += rotX;
	rY += rotY;
	rZ += rotZ;
}

void figura::set_rotate(float rotX, float rotY, float rotZ)
{
	rX = rotX;
	rY = rotY;
	rZ = rotZ;

}
