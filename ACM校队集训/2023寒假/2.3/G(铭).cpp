#include <bits/stdc++.h>
#define double long double
using namespace std;
const int N = 2e5 + 5;
const double pi = 3.14159265358979323846;
const double eps = 1e-8;

int t, n;

struct Ball {
	int x, y, z;
	int r;
};

void init () {}

double get_dis (Ball &a, Ball &b) {
	return sqrt ((a.x - b.x) * (a.x - b.x) +
	(a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

double get_h (Ball &a, Ball &b, double dis) {
	return a.r - (a.r * a.r + dis * dis - b.r * b.r) / (2 * dis);
}

double cal (Ball &a, Ball &b) {
	double dis = get_dis (a, b);
	double h1 = get_h (a, b, dis), h2 = get_h (b, a, dis);
	return pi * h1 * h1 * (a.r - h1 / 3) + pi * h2 * h2 * (b.r - h2 / 3);
}

void charming (int cnt) {
	init ();
	cin >> n;
	vector <Ball> b (n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i].x >> b[i].y >> b[i].z >> b[i].r;
	}
	Ball c;
	cin >> c.x >> c.y >> c.z >> c.r;
	double res = 0;
	for (int i = 0; i < n; ++i) {
		double dis = get_dis (b[i], c);
		if (dis <= eps) res += (double) 4 * pi * min (b[i].r, c.r) 
		* min (b[i].r, c.r) * min (b[i].r, c.r) / 3;
		else if (dis + b[i].r <= c.r + eps)
		res += (double) 4 * pi * b[i].r * b[i].r * b[i].r / 3;
		else if (dis + c.r <= b[i].r + eps)
		res += (double) 4 * pi * c.r * c.r * c.r / 3;
		else if (dis < b[i].r + c.r)
		res += cal (b[i], c);
	}
	cout << setprecision (15) << "Case #" << cnt << ": " << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}