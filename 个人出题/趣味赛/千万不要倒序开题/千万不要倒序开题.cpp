#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
vector <array <int, 4> > data;

void init () {}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		array <int, 4> d;
		d[0] = i;
		cin >> d[1] >> d[2] >> d[3];
		data.emplace_back (d);
	}
	sort (data.begin (), data.end (), [](array <int, 4> &a, 
	array <int, 4> &b) {return (double) a[3] / a[2] < (double) b[3] / b[2];});
	int tims = 0, sco = 0, res = 0;
	for (auto [a, b, c, d] : data) {
		if (tims + d > m) break;
		res += b - tims * (c);
		tims += d;
	}
	cout << res << endl;
	tims = 0;
	for (auto [a, b, c, d] : data) {
		tims += d;
		if (tims > m) break;
		//cout << a << " ";
	}
}

signed main () {
	charming ();
	return 0;
}