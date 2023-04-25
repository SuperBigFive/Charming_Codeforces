#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, h;

void init () {}

int check (vector <int> &a, int ch, int mul[3]) {
	bool ok = true;
	int cnt = 0, i;
	for (i = 0; i < n; ++i) {
		while (a[i] >= ch && cnt < 3) 
		ch *= mul[cnt++];
		if (a[i] >= ch) {
			ok = false;
			break;
		}
		ch += a[i] / 2;
	}
	return i;
}

void charming () {
	init ();
	cin >> n >> h;
	vector <int> a (n);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end ());
	int res = 0;
	int mul[3] = {2, 2, 3};
	res = max (res, check (a, h, mul));
	mul[0] = 2, mul[1] = 3, mul[2] = 2;
	res = max (res, check (a, h, mul));
	mul[0] = 3, mul[1] = 2, mul[2] = 2;
	res = max (res, check (a, h, mul));
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}