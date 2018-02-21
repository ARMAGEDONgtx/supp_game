#pragma once

#include "figura.h"
#include <vector>


class Przeszkoda : public figura
{
protected:
	bool m_aktywna;
	std::vector<figura*> elementy;

public:
	Przeszkoda(float x, float y, kolor k, bool aktywny);
	~Przeszkoda();

	virtual void rysuj() = 0;
	

};
