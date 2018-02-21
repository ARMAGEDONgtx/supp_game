#include"bielan_przeszkoda_1.h"


void Przeszkoda_Bielan_1::collision(gracz &gracz_1, gracz &gracz_2)
{
    if (gracz_1.Kolizja(aktywator_1) || gracz_2.Kolizja(aktywator_1))
    {
        m_aktywna = false;
        aktywator_1.change_color(kolor(0, 0, 1));
    }
    else if (gracz_1.Kolizja(aktywator_2) || gracz_2.Kolizja(aktywator_2))
    {
        m_aktywna = false;
        aktywator_2.change_color(kolor(0, 0, 1));
    }

    else
    {
        m_aktywna = true;
        aktywator_1.change_color(kolor(1, 1, 1));
        aktywator_2.change_color(kolor(1, 1, 1));
    }


    if (m_aktywna == true)
    {
        for (int i = 0; i < kulki.size(); i++)
        {
            if (gracz_1.Kolizja(kulki[i]))
            {
                //gracz_1.UstawFizyke(10, -90);
                gracz_1.move(0, 0.3);
                gracz_1.UstawPredkosc(40, 160);
            }
            if (gracz_2.Kolizja(kulki[i]))
            {
                //gracz_2.UstawFizyke(10, -90);
                gracz_2.move(0, 0.3);
                gracz_2.UstawPredkosc(40, 160);
            }
        }
    }




}



void Przeszkoda_Bielan_1::action()
{

    float i;

    if (kat > 0)
    {
        i = 270 + kat;

    }
    else if (kat < 0)
    {

        i = 270 + kat;

    }
    else if (kat == 0)
    {
        i = 270;

    }
    float rad = (i*3.14) / 180;

    if (m_aktywna)
    {

        if (kat > 90)
        {
            abc = 1;
        }
        if (kat < -90)
        {
            abc = 2;
        }






        switch (abc)
        {
        case 1:
        {
            kat -= 1.5;

            wahadlo.set_rotate(0, 0, kat);

            kula.set_position(wahadlo.wsp_x() + wahadlo.zwroc_wyskosc_belki()*cos(rad), wahadlo.wsp_Y() + wahadlo.zwroc_wyskosc_belki()*sin(rad));
            for (float i = 0; i < 3; i++)
            {
                kulki[i].set_position((wahadlo.wsp_x() +( wahadlo.zwroc_wyskosc_belki()*cos(rad))*((i + 1.0) / 4)) , ((wahadlo.wsp_Y() +(( wahadlo.zwroc_wyskosc_belki()*sin(rad)) * (((i + 1.0) / 4.0))))));
            }
            break;
        }
        case 2:
        {
            kat += 1.5;

            wahadlo.set_rotate(0, 0, kat);
            kula.set_position(wahadlo.wsp_x() + wahadlo.zwroc_wyskosc_belki()*cos(rad), wahadlo.wsp_Y() + wahadlo.zwroc_wyskosc_belki()*sin(rad));
            for (float i = 0; i < 3; i++)
            {
                kulki[i].set_position((wahadlo.wsp_x() + (wahadlo.zwroc_wyskosc_belki()*cos(rad))*((i+1.0)/4)), ((wahadlo.wsp_Y() + ((wahadlo.zwroc_wyskosc_belki()*sin(rad)) * (((i + 1.0) / 4.0))))));
            }
            break;
        }
        }
    }
    else
    {
        wahadlo.set_rotate(0, 0, 90);
        kat = 90.001;
        //kula.set_rotate(0, 0, 90);
        kula.set_position(wahadlo.wsp_x() + wahadlo.zwroc_wyskosc_belki() + kula.zwroc_promien()*cos(0), wahadlo.wsp_Y() + kula.zwroc_promien()*sin(0));
        for (int i = 0; i < 3; i++)
        {
            kulki[i].set_position((wahadlo.wsp_x() + wahadlo.zwroc_wyskosc_belki()*cos(0)) / ((i + 1) / 4), ((wahadlo.wsp_Y() + wahadlo.zwroc_wyskosc_belki()*sin(0)) / ((i + 1) / 4)));
        }
    }



}

void Przeszkoda_Bielan_1::rysuj()
{
    aktywator_1.rysuj();
    aktywator_2.rysuj();
    kula.rysuj();
    wahadlo.rysuj();



}
