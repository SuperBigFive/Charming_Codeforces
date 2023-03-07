#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define pi 3.141592653589793238462643383279
using namespace std;
const int maxn = 2e6 + 5;

void init () {}

void charming () {
	init ();
	double a, b, d;
	scanf ("%lf%lf%lf", &a, &b, &d);
	d = d * pi / (double)180.0 ;
	double tmpa = a, tmpb = b;
	a = tmpa * cos (d) - tmpb * sin (d);
	b = tmpb * cos (d) + tmpa * sin (d);
	printf ("%.20lf %.20lf\n", a, b);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
