// Fractal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Func.h"

#define FRAME_WIDTH 500
#define FRAME_HEIGHT 500

unsigned char FRAME[FRAME_HEIGHT][FRAME_WIDTH];

void Init(void) {
	COMPLEX c = { 0.33, 0.40 };
	int i, j;

	for (i = 0; i < FRAME_HEIGHT; i++) {
		for (j = 0; j < FRAME_WIDTH; j++) {
			COMPLEX z = { 2.0 * i / FRAME_HEIGHT - 1,
				2.0 * j / FRAME_WIDTH - 1 };
			int n = 0;
			while ((Abs(z) < 2) && (n < 255))
			{
				z = ComplAddCompl(ComplMultCompl(z, z), c);
				n++;
			}
			FRAME[i][j] = n;
		}
	}
}

void Keyboard(unsigned char Key, int X, int Y)
{
	if (Key == 27)
		exit(0);
}

void Display(void) {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawPixels(FRAME_WIDTH, FRAME_HEIGHT, GL_LUMINANCE, GL_UNSIGNED_BYTE, FRAME);
	
	glFinish();
	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	Init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(FRAME_WIDTH, FRAME_HEIGHT);
	glutCreateWindow("OPEN GL");

	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);

	glutMainLoop();

    return 0;
}

