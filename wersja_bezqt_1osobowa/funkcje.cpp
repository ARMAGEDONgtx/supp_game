#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>
#include "figury.h"
#include <ctime>
#include <vector>
#include "czlowiek.h"
#include"gracz.h"
#include "funckje.h"
#include "wrobel_dzialo.h"
#include "wrobel_przeszkoda_1.h"
#include"bielan_przeszkoda_1.h"
bool prostokat::hide = !false;;
bool kolo::hide = !false;
bool trojkat::hide = !false;
bool belka::hide = !false;
bool klawisze[256];
std::vector<prostokat> przeszkody;
std::vector<Przeszkoda*> PP;
prostokat podloga(0, -20, kolor(1, 0, 0), 1000, 4);

bool kolizja = false;
float Left = -20;
float Right = 20;
float Up = 20;
float Bottom = -20;
float Near = -20;
float Far = 20;
float x_cam = 0;
float y_cam = 0;
float z_cam = 5;
float x_o = 0;
float y_o = 0;
float z_o = 0;

bool Czy_moze_prawo = true;
bool Czy_moze_lewo = true;
//fasfsdfas

int arg = 0;
figura *active = new kolo(1, 1, kolor(1, 1, 1), 1);
gracz gracz_1(0, -10, kolor(0, 1, 1), 10, 4);





void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);





}

void strzalki(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		active->rotate(0, 0, 0.5);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		active->rotate(0, 0, -0.5);
		break;
	}
	}
}



void klawiatura(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
	{
		klawisze['a'] = true;

		break;
	}
	case 'd':
	{
		klawisze['d'] = true;


		break;
	}
	case ' ':
	{
		klawisze[' '] = true;

		break;
	}
	case 'w':
	{

		break;
	}
	case 's':
	{

		break;
	}
	case 'k':
	{

		break;
	}
	case 27:
	{
		exit(1);
		break;
	}
	}
	glutPostRedisplay();
}

void keyup(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
	{
		klawisze['a'] = false;
		break;
	}
	case 'd':
	{
		klawisze['d'] = false;
		break;
	}
	case ' ':
	{
		klawisze[' '] = false;
		break;
	}
	}
}
void MouseClick(int button, int state, int X, int Y)
{
	float wspx = glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT) / 2.0 * 5.0;
	float wspy = 1 / Right * 5;
	float glX = (float(X) - glutGet(GLUT_WINDOW_WIDTH) / 2) / glutGet(GLUT_WINDOW_WIDTH) * Right * 2;
	float glY = -(float(Y) - glutGet(GLUT_WINDOW_HEIGHT) / 2) / glutGet(GLUT_WINDOW_HEIGHT) * Right * 2;


	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		active->set_position(glX, glY);
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		kolo k(glX, glY, kolor(1, 1, 1), 1);

	}
	glutPostRedisplay();
}

void MouseMotion(int x, int y)
{
	float glX = (float(x) - glutGet(GLUT_WINDOW_WIDTH) / 2) / glutGet(GLUT_WINDOW_WIDTH) * Right * 2;
	float glY = -(float(y) - glutGet(GLUT_WINDOW_HEIGHT) / 2) / glutGet(GLUT_WINDOW_HEIGHT) * Right * 2;


}

void Czy_Kolizja( gracz &g,  prostokat &p)
{
	if((g.zwroc_y_gracza() - (0.6*(g.zwroc_wysokosc_gracza()))) < (p.wsp_Y() - 0.1 + (p.zwroc_wyskosc_prostokata()) / 2.0))
	{
		if (klawisze['d'])
		{
			Czy_moze_prawo = false;
			gracz_1.ruch(-0.05, 0);

		}
		if (klawisze['a'])
		{

			Czy_moze_lewo = false;
			gracz_1.ruch(0.005, 0);
		}

	}
	else
	{
		Czy_moze_prawo = true;
		Czy_moze_lewo = true;
	}
	
	
}

void kolizje()
{
	//KOLIZJE**************************************
	kolizja = false;

	for (int i = 0; i < przeszkody.size(); i++)
	{
		if (gracz_1.Kolizja(przeszkody[i]))
		{
			kolizja = true;
			Czy_Kolizja(gracz_1, przeszkody[i]);
		}
	}
	if (gracz_1.Kolizja(podloga))
	{
		kolizja = true;
	}




	if (kolizja)
	{
		gracz_1.UstawFizyke(0, -90);
		gracz_1.UstawPredkosc(0, 0);
	}
	else
	{

		gracz_1.UstawFizyke(100, -90);
	}
}


void strzal(int arg)
{
	for (int i = 0; i < PP.size();i++)
	{ 
		PP[i]->action();
	}
	
	glutTimerFunc(5000, strzal, 0);
}

void loop()
{
	//STEROWANIE******************************
	if (klawisze['a'])
	{
		if (Czy_moze_lewo)
		{
			gracz_1.ruch(-0.01, 0);

			gracz_1.chod(arg);

		}
	
			
	}
	if (klawisze['d'])
	{
		if (Czy_moze_prawo)
		{
			gracz_1.ruch(0.01, 0);

			gracz_1.chod(arg);
		}
		
		

	}Czy_moze_lewo = true;
	Czy_moze_prawo = true;
	if (klawisze[' '])
	{
		if (gracz_1.Kolizja(podloga))
		{
			gracz_1.UstawPredkosc(30, 90);
			gracz_1.UstawFizyke(100, 270);
			gracz_1.ruch(0, 0.1);
		}

		for (int i = 0; i < przeszkody.size(); i++)
		{
			if (gracz_1.Kolizja(przeszkody[i]))
			{
				gracz_1.UstawPredkosc(30, 90);
				gracz_1.UstawFizyke(100, 270);
				gracz_1.ruch(0, 0.1);
			}
		}
	}

	kolizje();

	for (int i = 0; i < PP.size(); i++)
	{
		PP[i]->collision(gracz_1);
		PP[i]->collision_gracz(gracz_1);
	}

	x_o = gracz_1.wsp_x();
	x_cam = x_o;
	y_o = gracz_1.wsp_Y();
	y_cam = y_o;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0, 20.0, -20.0, 20.0, -20, 20.0);
	gluLookAt(x_cam, y_cam, z_cam, x_o, y_o, z_o, 0, 1, 0);

	gracz_1.Aktualizuj(GetTickCount());
	gracz_1.Reset();
	gracz_1.aktualizuj();
	glutPostRedisplay();
}

up_n_down test(-40, -6, kolor(1, 1, 1), true, 40,10, 2, 6, 100);
Przeszkoda_Bielan_1 test_1(20,0,kolor(1,1,1),1);
void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	gracz_1.rysuj();

	for (int i = 0; i < przeszkody.size(); i++)
		przeszkody[i].rysuj();

	for (int i = 0; i < PP.size(); i++)
		PP[i]->rysuj();

	//test
	test.rysuj();
	test.action();
	test.collision_gracz(gracz_1);
	//test_1
	test_1.rysuj();
	test_1.action();
	test_1.collision(gracz_1);



	podloga.rysuj();
	glPopMatrix();

	glutSwapBuffers();
}

void InitGLUTScene(char* window_name)
{
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("ELO");

	// set white as the clear colour
	glClearColor(1, 1, 0, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		przeszkody.push_back(prostokat((i + 1) * 8 - 20 + rand() % 10, -16, kolor(0, 0.5, 1), 2, 4));
	}

	gracz_1.UstawFizyke(20, -90);
	PP.push_back(new dzialo(10,-16,kolor(1,1,1),true,2));
	//przeszkody.push_back(new dzialo(10, -16, kolor(1, 1, 1), true, 2));

}

void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(klawiatura);
	glutKeyboardUpFunc(keyup);
	glutMouseFunc(MouseClick);
	glutPassiveMotionFunc(MouseMotion);
	glutSpecialFunc(strzalki);
	glutIdleFunc(loop);
	glutTimerFunc(1000, strzal, 0);
}