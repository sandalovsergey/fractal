#include "stdafx.h"
#include "Func.h"

COMPLEX Create(double a, double b)
{
	COMPLEX res;
	res.Re = a;
	res.Im = b;
	return res;
}

COMPLEX ComplAddCompl(COMPLEX a, COMPLEX b) {
	COMPLEX res;
	res.Re = a.Re + b.Re;
	res.Im = a.Im + b.Im;
	return res;
}

COMPLEX ComplMultCompl(COMPLEX a, COMPLEX b) {
	COMPLEX res;
	res.Re = a.Re * b.Re - a.Im * b.Im;
	res.Im = a.Re * b.Im + a.Im * b.Re;
	return res;
}

double Abs(COMPLEX z) {
	double res;
	res = sqrt(z.Re * z.Re + z.Im * z.Im);
	return res;
}