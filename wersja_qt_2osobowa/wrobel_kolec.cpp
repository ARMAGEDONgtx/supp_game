#include "wrobel_kolec.h"

void kolec::collision_gracz(gracz & g)
{
    if (this->Kolizja(g))
    {
        g.get_dmg();
        g.get_dmg();
    }
}

void kolec::rysuj()
{
    kol.rysuj();
}
