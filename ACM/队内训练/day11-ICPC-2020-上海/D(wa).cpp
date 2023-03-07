#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t;

void init () {}

void charming () {
	init ();
	double n;
	cin >> n;
	vector <array <double, 2> > pv (3);
	cin >> pv[0][0] >> pv[0][1] >> pv[1][0] >> pv[1][1];
	if (pv[0][0] > pv[1][0]) swap (pv[0], pv[1]);
	double res = LLONG_MAX, tim = 0, p1, p2, tim1, tim2, tim3;
	pv[2][0] = n + n - pv[1][0], pv[2][1] = pv[1][1];
	// first method -> / <- / ->
	tim1 = (pv[1][0] - pv[0][0]) / pv[0][1];
	if (tim1 * pv[2][1] >= pv[2][0]) res = min (res, pv[2][0] / pv[2][1]);
	else {
		p1 = pv[1][0], p2 = pv[2][0] - tim1 * pv[2][1];
		tim2 = p1 / pv[0][1];
		if (p2 - tim2 * pv[2][1] < 0) res = min (res, tim1 + p2 / pv[2][1]);
		else {
			p1 = 0, p2 = p2 - tim2 * pv[2][1];
			tim3 = (p2 - p1) / (pv[0][1] + pv[2][1]);
			if (p2 <= n) res = min (res, tim1 + tim2);
			else if (pv[0][1] * tim3 >= n) res = min (res, tim1 + tim2 + tim3);
			else res = min (res, tim1 + tim2 + (p2 - n) / pv[2][1]);
		}
	}
	// second method -> / <-
	tim1 = (pv[2][1] - pv[0][0]) / (pv[0][1] + pv[2][1]);
	p1 = p1 + pv[0][1] * tim1, p2 = p2 - pv[0][2] * tim1;
	res = min (res, tim1 + p2 / max (pv[0][1], pv[2][1]));
	// third mehod <- / ->
	tim1 = pv[0][0] / pv[0][1];
	if (tim1 * pv[2][1] >= pv[2][0]) res = min (res, pv[2][0] / pv[2][1]);
	else {
		p1 = 0, p2 = pv[2][0] - tim1 * pv[2][1];
		if (p2 > n) {
			tim2 = (p2 - n) / pv[2][1];
			if (tim1 * pv[0][1] >= n) res = min (res, tim1 + (p2 - p1) / (pv[0][1] + pv[2][1]));
			if (tim1 * pv[0][1] >= pv[1][0]) res = min (res, tim1 + tim2);
			else {
				p1 = tim1 * pv[0][1], p2 = n;
				tim3 = (pv[1][0] - p1) / pv[0][1];
				if (p2 - tim3 * pv[2][1] >= pv[1][0]) res = min (res, tim1 + tim2 + tim3);
				else res = min (res, tim1 + tim2 + (p2 - p1) / (pv[0][1] + pv[2][1]));
			}
		}
		else {
			tim2 = pv[1][0] / pv[0][1];
			if (p2 - tim2 * pv[2][1] >= pv[1][0]) res = min (res, tim1 + tim2);
			else res = min (res, tim1 + (p2 - p1) / (pv[0][1] + pv[2][1]));
		}
	}
	pv[2][0] = -pv[1][0], pv[2][1] = pv[1][1];
	// first method <- / ->
	p1 = pv[0][0], p2 = pv[2][0];
	tim1 = (p1 - p2) / (pv[0][1] + pv[2][1]);
	p1 = p2 = -tim1 * pv[0][1];
	res = min (res, tim1 + (n - p1) / max (pv[0][1], pv[2][1]));
	// secon method -> / <-
	tim1 = (n - p1) / pv[0][1];
	if (p2 + tim1 * pv[2][1] >= n) res = min (res, (n - p2) / pv[2][1]);
	else if (p2 + tim1 * pv[2][1] >= 0) res = min (res, tim1);
	else {
		p1 = n, p2 = p2 + tim1 * pv[2][1];
		tim2 = (0 - p2) / pv[2][1];
		if (p1 - tim2 * pv[0][1] > 0) res = min (res, tim1 + tim2);
		else res = min (res, tim1 + (p1 - p2) / (pv[0][1] + pv[2][1]));
	}
	cout << setprecision (15) << fixed << res << endl;
}

signed main () {
	cin >> t;
	while (t--)	charming ();
	return 0;
}