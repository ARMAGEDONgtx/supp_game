#include "funckje.h"
#include <GL/freeglut.h>
#include <ctime>


int main(int argc, char *argv[])
{

	srand(time(NULL));
	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();

	
	glutMainLoop();

	return 0;
}