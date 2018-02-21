#include "wrobel_gate.h"

void gate::loadtextures()
{
    brama.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\gate.jpg", 5);
    sciana.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\castle.jpg", 5);
    gora.LoadGLTextures("C:\\Users\\Michal\\Desktop\\textury\\gate.jpg", 5);
}

void gate::collision_gracz(gracz & g)
{
    if (g.Kolizja(aktywator))
    {
        opened = true;
    }
    if (!opened)
    {
        if (g.Kolizja(brama) || g.Kolizja(gora) || g.Kolizja(sciana))
        {
            g.czy_moze_prawo = false;
        }
    }
}

void gate::rysuj()
{
if (!opened)
{
    brama.rysuj();
}
    gora.rysuj();
    sciana.rysuj();

    aktywator.rysuj();

}
