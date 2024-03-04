#include <iostream>
#include <stdlib.h>
#include <cmath>
#define xp(x,y) y
#define yp(x,y) ((-2*y)-(78.48*x))
 
using namespace std;

void RK4sys(float, float, int, float, float, float* , float*);
int main() {
	float ma = 0;
	float mb = 1.5;
	int n = 1;
	float mxb = 0;
	float mxa = 0.02;
	float x, y;
	RK4sys(ma, mb, n, mxa, mxb, &x,&y);
	cout << " at " << n << " step(s) the values are: " << endl;
	cout << "displacement: " << x << endl;
	cout << "velocity: " << y << endl;
	cout << "acceleration: " << yp(x, y) << endl;
}
void RK4sys(float a,float b, int step,float xa, float ya, float *x, float *y) {
	int j;
	float h, t, k11, k12, k21, k22, k31, k32, k41, k42;
	*x = xa;
	*y = ya;
	t = a;	
	h = (b - a)/step;

	for (j = 1; j <= step; j++) {
		k11 = h * (xp(*x, *y));
		k12 = h * (yp(*x, *y));
		k21 = h* (xp( *x+(k11/2), *y+(k12/2)));
		k22 = h* (yp( *x + (k11 / 2), (*y + (k12 / 2))));
		k31 = h* (xp( *x + (k21 / 2), (*y + (k22 / 2))));
		k32 = h* (yp( *x + (k21 / 2), (*y + (k22 / 2))));
		k41 = h* (xp( *x+k31, *y+k32));
		k42 = h* (yp( *x+k31, *y+k32));
		*x = (*x + (0.16666) * (k11 + (2 * k21) + (2 * k31) + k41));
		*y = (*y+ (0.16666) * (k12 + (2 * k22) + (2 * k32) + k42));
		t = t + h;
	}
}