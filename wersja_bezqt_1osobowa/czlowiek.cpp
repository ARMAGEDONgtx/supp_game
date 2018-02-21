#include "czlowiek.h"

#include <iostream>
void czlowiek::rysuj()
{
	if (widoczny)
	{
		glPushMatrix();
		for (int i = 0; i < cialo.size(); i++)
		{
			cialo[i]->rysuj();
		}
		glPopMatrix();
	}
}




