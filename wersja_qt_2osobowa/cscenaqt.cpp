#include <iostream>

#define NDEBUG
//#include <GL/freeglut.h>
#include "figury.h"
#include <ctime>
#include <vector>
#include "czlowiek.h"
#include"gracz.h"
#include "funckje.h"
#include "wrobel_dzialo.h"
#include "wrobel_przeszkoda_1.h"
#include"bielan_przeszkoda_1.h"
#include "wrobel_gate.h"
#include "Pawlak_winda.h"
#include "Gnom.h"
#include "Pawlak_slupki.h"
#include "wrobel_most.h"
#include "wrobel_przepasc.h"
#include "boss.h"
#include "Pawlak_wieze.h"
#include "cscenaqt.h"
#include <gl/GLU.h>
#include <gl/GL.h>
bool prostokat::hide = !false;
bool kolo::hide = !false;
bool trojkat::hide = !false;
bool belka::hide = !false;
bool klawisze[256];
std::vector<figura*> przeszkody;
prostokat podloga(0, -20, kolor(1, 0, 0), 1000, 4);
prostokat podloga_2(125, -5, kolor(1, 0, 0), 150, 4);
prostokat sciana(54, -12.5, kolor(1, 0, 0), 8, 11);
float ilosc_klatek = 150;
bool kolizja = false;
float Left = -40;
float Right = 40;
float Up = 40;
float Bottom = -40;
float Near = -20;
float Far = 20;
float x_cam = 0;
float y_cam = 0;
float z_cam = 5;
float x_o = 0;
float y_o = 0;
float z_o = 0;


int arg = 0;
figura *active = new kolo(1, 1, kolor(1, 1, 1), 1);
gracz gracz_1(240, 0, kolor(1, 1, 1), 6, 3);
gracz gracz_2(240, 0, kolor(1, 1, 1), 6, 3);
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <gl/GLU.h>
#include <gl/GL.h>
#include "webdlg.h"
void Czy_kolizja2(gracz &g, figura* obiekt)
{
    g.czy_moze_lewo = true;
    g.czy_moze_prawo = true;
    g.czy_moze_skok = true;
    if (g.Kolizja(*obiekt))
    {
        g.ruch(0, 0.5);
        if (g.Kolizja(*obiekt))
        {
            g.ruch(0.5, 0);
            if (g.Kolizja(*obiekt))
            {
                g.czy_moze_prawo = false;
            }
            else g.czy_moze_prawo = true;
            g.ruch(-0.5, 0);

            g.ruch(-0.5, 0);
            if (g.Kolizja(*obiekt))
            {
                g.czy_moze_lewo = false;
            }
            else g.czy_moze_lewo = true;
            g.ruch(0.5, 0);
        }
        else
        {
            g.czy_moze_lewo = true;
            g.czy_moze_prawo = true;
        }
        g.ruch(0, -0.5);


        if (!g.czy_moze_lewo)
        {
            g.ruch(0.1, 0);
            g.czy_moze_skok = false;
        }
        else if (!g.czy_moze_prawo)
        {
            g.ruch(-0.1, 0);
            g.czy_moze_skok = false;
        }
    }

}

void Czy_Kolizja(gracz &g, prostokat &p)
{
    if ((g.zwroc_y_gracza() - (0.6*(g.zwroc_wysokosc_gracza()))) < (p.wsp_Y() - 0.1 + (p.zwroc_wyskosc_prostokata()) / 2.0))
    {
        if (klawisze['d'])
        {
            g.czy_moze_prawo = false;
            gracz_1.ruch(-0.05, 0);

        }
        if (klawisze['a'])
        {

            g.czy_moze_lewo = false;
            gracz_1.ruch(0.005, 0);
        }

    }
    else if (g.Kolizja(sciana))
    {
        g.czy_moze_prawo = false;
    }
    else
    {
        g.czy_moze_prawo = true;
        g.czy_moze_lewo = true;
    }



}



void kolizje(gracz &g, gracz &g2)
{
    //KOLIZJE**************************************
    kolizja = false;

    for (int i = 0; i < przeszkody.size(); i++)
    {
        if (g.Kolizja(*przeszkody[i]))
        {
            kolizja = true;
            Czy_kolizja2(g, przeszkody[i]);
            //Czy_Kolizja(gracz_1, przeszkody[i]);
        }
    }
    if (g.Kolizja(podloga))
    {
        kolizja = true;
        g.czy_moze_skok = true;
    }
    if (g.Kolizja(podloga_2))
    {
        kolizja = true;
        g.czy_moze_skok = true;
    }
    if (g.Kolizja(sciana))
    {
        kolizja = true;
        g.czy_moze_prawo = false;

    }

    if (g.Kolizja(g2))
    {
        if (g.wsp_Y() > g2.wsp_Y() + g2.zwroc_wysokosc_gracza() - 0.1 && g.wsp_Y() < g2.wsp_Y() + g2.zwroc_wysokosc_gracza() + 0.1)
        {
            g.czy_moze_skok = true;
            kolizja = true;
        }
    }


    if (kolizja)
    {
        g.UstawFizyke(0, -90);
        g.UstawPredkosc(0, 0);
    }
    else
    {

        g.UstawFizyke(100, -90);
    }
}



cScenaQt::cScenaQt(QWidget *parent)
    : QGLWidget(parent),ip("192.168.0.109"),port(1111) {
    m_timer_id = startTimer(1000/ilosc_klatek);
    setFocusPolicy(Qt::TabFocus);

    m_timer_id2 = startTimer(5000);



    client = new gameClient("192.168.0.109",1111,this);

    WebDlg *dialog = new WebDlg();


    dialog->set_data(ip,port);

    if(dialog->exec() == QDialog::Accepted)
    {
        ip = dialog->get_ip();
        port = dialog->get_port();

        client->setIP(ip);
        client->setPort(port);

    }

    delete dialog;


}



void cScenaQt::resizeGL(int w, int h)
{
    // setup viewport, projection etc.:
   glViewport(0, 0, w, h);


}
dzialo test_3(-90, -16, kolor(1, 1, 1), true, 2, 6);
boss bosss(260, 0, kolor(0, 0, 0), true, 10, 10);
up_n_down test(-350, -8, kolor(1, 0, 1), true, 40, 10, 2, 6, 100);
Przeszkoda_Bielan_1 test_1(-120, -17, kolor(1, 1, 1), 1);
gate test_2(-100, -14, kolor(1, 1, 1), 12, 5, true, false);
Pawlak_winda test_4(48, -18.5, kolor(1, 1, 1), true, 4, 1);
Gnom test_5(500, -16, kolor(1, 1, 1), true,1,3);
Pawlak_slupki test_6(90, -2.5, kolor(1, 1, 1), true, 1, 12);
most test_7(0, -8, kolor(0, 0, 1), true, 50, 20);
przepasc test_8(-200, -6, kolor(1, 1, 1), true, 80, 30);
Pawlak_wieze test_9(165,0,kolor(1,1,1),true,3,6,3,3);
prostokat tlo(0, -10, kolor(1, 1, 1), 120, 120);

void cScenaQt::initializeGL()
{
    // Set up the rendering context, define display lists etc.:


            // set white as the clear colour
            glClearColor(1, 1, 0, 1);

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);
            glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping ( NEW )
            glShadeModel(GL_SMOOTH);
            glEnable(GL_LIGHT0);
            glEnable(GL_NORMALIZE);
            glEnable(GL_COLOR_MATERIAL);

            srand(time(NULL));

            test_8.loadtextures();
            test_2.loadtextures();
            test_3.loadtextures();
            test.loadtextures();
            test.set_position(-350,-8);

            bosss.loadtextures();
            gracz_1.zaladuj_textury();
            gracz_2.zaladuj_textury2();
            podloga.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\bricks.jpg",5);
            podloga_2.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\bricks.jpg", 5);
            tlo.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\tlo.jpg", 5);
            gracz_1.Reset();
            gracz_2.Reset();
            gracz_1.set_position(gracz_1.wsp_x(), -10);


            bosss.Reset();

}


void cScenaQt::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    gracz_1.rysuj();
    gracz_2.rysuj();
    for (int i = 0; i < przeszkody.size(); i++)
    {
        przeszkody[i]->rysuj();
    }


    //test
    test.rysuj();
    test.action();
    test.collision_gracz(gracz_1);

    //test_1
    test_1.rysuj();


    test_1.collision(gracz_1, gracz_2);
    test_1.action();
    //test_2
    test_2.rysuj();
    test_2.collision_gracz(gracz_1);
    //test_3
    test_3.rysuj();
    test_3.collision_gracz(gracz_1);
    test_3.collision(gracz_1);

    //test_4
    test_4.rysuj();
    test_4.action();
    test_4.collision_gracz(gracz_1);

    //test_5
    test_5.rysuj();
    test_5.action();
    test_5.collision_gracz(gracz_1);

    //test_6
    test_6.rysuj();
    test_6.action();
    test_6.collision_gracz(gracz_1);

    //test 7
    test_7.rysuj();
    test_7.collision_gracz(gracz_1);

    //test 8
    test_8.rysuj();
    test_8.collision_gracz(gracz_1);

    //test 9
    test_9.rysuj();
    test_9.collision_gracz(gracz_1);

    //boss
    bosss.rysuj();
    bosss.collision_gracz(gracz_1);

    bosss.collision(podloga);
    //podłogi
    podloga.rysuj();
    podloga_2.rysuj();

    sciana.rysuj();

    tlo.rysuj();
    glPopMatrix();
    makeCurrent();
    QGLWidget::swapBuffers();
}

void cScenaQt::mouseMoveEvent(QMouseEvent *event)
{

    float disp_x=event->pos().x();
    float disp_y=event->pos().y();

    m_x=2.0/this->width()*disp_x-1;
    m_y=2.0/this->height()*(this->height()-disp_y)-1;

    update();
}

void cScenaQt::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_A:
    {
        klawisze['a'] = true;
        break;
    }
    case Qt::Key_D:
    {
        klawisze['d'] = true;
        break;
    }
    case Qt::Key_Space:
    {
        klawisze[' '] = true;
        break;
    }
    }
}
void cScenaQt::keyReleaseEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_A:
    {
        klawisze['a'] = false;
        break;
    }
    case Qt::Key_D:
    {
        klawisze['d'] = false;
        break;
    }
    case Qt::Key_Space:
    {
        klawisze[' '] = false;
        break;
    }
    }
}

void moving_players()
{
    //STEROWANIE******************************
    if (klawisze['a'])
    {
        if (gracz_1.czy_moze_lewo)
        {
            gracz_1.ruch(-20.0/ilosc_klatek, 0);

            gracz_1.chod(arg);

        }
    }
    if (klawisze['d'])
    {
        if (gracz_1.czy_moze_prawo)
        {
            gracz_1.ruch(20.0/ilosc_klatek, 0);

            gracz_1.chod(arg);
        }



    }
    if (klawisze[' '])
    {
        if (gracz_1.Kolizja(podloga) && gracz_1.czy_moze_skok)
        {
            gracz_1.UstawPredkosc(35, 90);
            gracz_1.UstawFizyke(100, 270);
            gracz_1.ruch(0, 0.1);
        }
        if (gracz_1.Kolizja(podloga_2) && gracz_1.czy_moze_skok)
        {
            gracz_1.UstawPredkosc(35, 90);
            gracz_1.UstawFizyke(100, 270);
            gracz_1.ruch(0, 0.1);
        }
        for (int i = 0; i < przeszkody.size(); i++)
        {
            if (gracz_1.Kolizja(*przeszkody[i]) && gracz_1.czy_moze_skok)
            {
                gracz_1.UstawPredkosc(35, 90);
                gracz_1.UstawFizyke(100, 270);
                gracz_1.ruch(0, 0.1);
            }
        }
        if (gracz_1.Kolizja(gracz_2))
        {
            if (gracz_1.wsp_Y() > gracz_2.wsp_Y() + gracz_2.zwroc_wysokosc_gracza() - 0.1 && gracz_1.wsp_Y() < gracz_2.wsp_Y() + gracz_2.zwroc_wysokosc_gracza() + 0.1)
            {
                gracz_1.UstawPredkosc(35, 90);
                gracz_1.UstawFizyke(100, 270);
                gracz_1.ruch(0, 0.1);
            }
        }
        if (gracz_1.zezwolenie_na_skok)
        {
            gracz_1.UstawPredkosc(35, 90);
            gracz_1.UstawFizyke(100, 270);
            gracz_1.ruch(0, 0.1);
        }
    }
    gracz_1.czy_moze_lewo = true;
    gracz_1.czy_moze_prawo = true;
    gracz_1.czy_moze_skok = true;
    kolizje(gracz_1, gracz_2);

    tlo.set_position(x_o,tlo.wsp_Y());

    //KAMERKAAAA&********************************************************************
    x_o = gracz_1.wsp_x();
    x_cam = x_o;
    y_o = gracz_1.wsp_Y();
    y_cam = y_o;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-40.0, 40.0, -40.0, 40.0, -20, 20.0);
    gluLookAt(x_cam, y_cam, z_cam, x_o, y_o, z_o, 0, 1, 0);



    gracz_1.Aktualizuj(GetTickCount());
    gracz_1.Reset();
    gracz_1.aktualizuj();
    gracz_2.Aktualizuj(GetTickCount());
    gracz_2.Reset();
    gracz_2.aktualizuj();
    //*******************************************************************************
}



void cScenaQt::timerEvent(QTimerEvent *event)
{

    if(event->timerId()==m_timer_id)
        {

        //KAMERKAAAA&********************************************************************

       moving_players();
       client->aktualizuj_dane(gracz_1.wsp_x(),gracz_1.wsp_Y());
       client->swapData();

       gracz_2.set_position(client->gracz_coop.wsp_x,client->gracz_coop.wsp_y);
       paintGL();



        }
    if(event->timerId() == m_timer_id2)
    {
        test_3.action();
        bosss.action();
    }

}
