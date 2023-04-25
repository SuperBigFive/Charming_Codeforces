#include <bits/stdc++.h>
#define T_ double
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;

T_ a, h, x;

void charming () {
	scanf ("%lf%lf%lf", &a, &h, &x);
	T_ angle;
	if (x >= (h * a * a / 2)) {
		angle = atan (2 * (a * a * h - x) / (a * a * a)) * 180 / pi;
	}
	else {
		angle = atan ((a * h * h) / (2 * x)) * 180 / pi;
	}
	printf ("%.10f\n", angle);
}

signed main () {
	charming ();
	return 0;
}