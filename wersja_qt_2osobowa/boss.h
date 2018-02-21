#ifndef BOSS_H
#define BOSS_H


#include "Gnom.h"
#include <vector>

class boss : public Gnom
{
    std::vector<Gnom> gnomy;
    prostokat aktywator;

public:
    boss(float x, float y, kolor k, bool active, float zycie, float size)
        : Gnom(x, y, k, active, zycie, size), aktywator(x-40, y, k, 50, 100)
    {
    }
    void rysuj();
    void collision(Fizyka & obiekt);
    void collision_gracz(gracz &g);
    void action();
    //void loadtextures(){korpus.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\kaczmi_tex.bmp", 4); }
};

#endif // BOSS_H
