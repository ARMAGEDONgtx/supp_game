#include "figury.h"
#include <cmath>
prostokat::prostokat(float x, float y, kolor k, float dl, float wys)
    : figura(x, y, k), dlugosc(dl), wysokosc(wys)
{
    UstawGeometrie(x, y, -dl / 2, -wys / 2, dl / 2, wys / 2);
}

void prostokat::rysuj()
{
    glBindTexture(GL_TEXTURE_2D, textura);
    if (widoczny&&hide)
    {
        glPushMatrix();
        glColor3f(_kolor.red, _kolor.green, _kolor.blue);
        glTranslatef(m_x, m_y, 0);
        glRotatef(rX, 1, 0, 0);
        glRotatef(rY, 0, 1, 0);
        glRotatef(rZ, 0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 1); glVertex3f(-dlugosc / 2, wysokosc / 2, 0);
        glTexCoord2f(0, 0); glVertex3f(-dlugosc / 2, -wysokosc / 2, 0);
        glTexCoord2f(1, 0); glVertex3f(dlugosc / 2, -wysokosc / 2, 0);
        glTexCoord2f(1, 1); glVertex3f(dlugosc / 2, wysokosc / 2, 0);
        glEnd();
        glPopMatrix();
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}

float prostokat::zwroc_dlugosc_prostokata()
{
    return dlugosc;
}

float prostokat::zwroc_wyskosc_prostokata()
{
    return wysokosc;
}

kolo::kolo(float x, float y, kolor k, float r)
    : figura(x, y, k), promien(r)
{
    UstawGeometrie(x, y, -promien, -promien, promien, promien);
}

void kolo::rysuj()
{
    glBindTexture(GL_TEXTURE_2D, textura);
    if (widoczny&&hide)
    {
        glPushMatrix();
        glColor3f(_kolor.red, _kolor.green, _kolor.blue);
        glTranslatef(m_x, m_y, 0);
        glRotatef(rX, 1, 0, 0);
        glRotatef(rY, 0, 1, 0);
        glRotatef(rZ, 0, 0, 1);
        glBegin(GL_POLYGON);
        double x, y;
        for (int i = 0; i < 360; i += 1)
        {
            float radian = i * (3.14 / 180.0f);

            float xcos = (float)cos(radian);
            float ysin = (float)sin(radian);
            x = xcos * promien;
            y = ysin * promien;
            float tx = xcos * 0.5 + 0.5;
            float ty = ysin * 0.5 + 0.5;


            glTexCoord2f(tx, ty);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}

float kolo::zwroc_promien()
{
    return promien;
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
        glVertex3f(m_x, m_y + wysokosc / 2, 0);
        glVertex3f(m_x - podstawa / 2, m_y - wysokosc / 2, 0);
        glVertex3f(m_x + podstawa / 2, m_y - wysokosc / 2, 0);
        glEnd();
        glPopMatrix();
    }
}


belka::belka(float x, float y, kolor k, float dl, float wys)
    : figura(x, y, k), dlugosc(dl), wysokosc(wys)
{
    UstawGeometrie(x, y, -dl / 2, -wys, dl / 2, 0);
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
        glVertex3f(-dlugosc / 2, -wysokosc, 0);
        glVertex3f(dlugosc / 2, -wysokosc, 0);
        glVertex3f(dlugosc / 2, 0, 0);
        glEnd();
        glPopMatrix();
    }
}

float belka::zwroc_wyskosc_belki()
{
    return wysokosc;
}
