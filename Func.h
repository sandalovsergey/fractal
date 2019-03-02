#include "freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	double Re;
	double Im;

}COMPLEX;

COMPLEX Create(double a, double b);
COMPLEX ComplAddCompl(COMPLEX a, COMPLEX b);
COMPLEX ComplMultCompl(COMPLEX a, COMPLEX b);
double Abs(COMPLEX z);