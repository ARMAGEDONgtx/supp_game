#pragma once
#include "fizyka.h"
#include "GL\freeglut.h"

struct kolor
{
	float red, green, blue;

	kolor(float r=0,float g=0,float b=0) 
		: red(r), green(g),blue(b){}
};

class figura : public Fizyka
{
protected:
	kolor _kolor;
	float rX, rY, rZ;
	bool widoczny;
	
public:
	figura(float x, float y, kolor k);
	virtual void rysuj() = 0;
	void set_position(float x, float y);
	void move(float dx, float dy);
	void change_color(kolor k);
	void rotate(float rotX, float rotY, float rotZ);
	void set_rotate(float rotX, float rotY, float rotZ);
	void zmien_widocznosc() { widoczny = !widoczny; }
	float wsp_x() { return m_x; }
	float wsp_Y() { return m_y; }
}; 


