#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int mx = 1e9;

ll ax, ay, bx, by, cx, cy, dx, dy;

void init () {
	
}

void charming () {
	ax = -mx, ay = 0;
	bx = -1, by = mx;
	cx = 0, cy = -mx;
	dx = mx, dy = 1;
	cout << ax << ' ' << ay << endl;
	cout << bx << ' ' << by << endl;
	cout << cx << ' ' << cy << endl;
	cout << dx << ' ' << dy << endl;
}

signed main () {
	charming ();
	return 0;
}