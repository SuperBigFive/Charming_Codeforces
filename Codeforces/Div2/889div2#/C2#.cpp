#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), b;
	pair <int, int> mx (-21, -1), mn (21, -1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > mx.first) mx.first = a[i], mx.second = i;
		if (a[i] < mn.first) mn.first = a[i], mn.second = i;
	}
	int ok_mx = 0, ok_mn = 0;
	vector <pair <int, int> > ans_mx, ans_mn;
	b = a;
	if (mx.first > 0) {
		a = b;
		ok_mx = 1;
		int id = mx.second;
		while (a[id] + a[1] < -mn.first) {
			ans_mx.emplace_back (make_pair (id, id));
			a[id] += a[id];
		}
		if (a[1] < -mn.first) {
			ans_mx.emplace_back (make_pair (1, id));
			a[1] += a[id];
		}
		for (int i = 2; i <= n; ++i) {
			while (a[i] < a[i - 1]) {
				ans_mx.emplace_back (make_pair (i, i - 1));
				a[i] += a[i - 1];
			}
		}
	}
	if (mn.first < 0) {
		a = b;
		ok_mn = 1;
		int id = mn.second;
		while (-a[id] - a[n] < mx.first) {
			ans_mn.emplace_back (make_pair (id, id));
			a[id] += a[id];
		}
		if (a[n] > -mx.first) {
			ans_mn.emplace_back (make_pair (n, id));
			a[n] += a[id];
		}
		for (int i = n - 1; i >= 1; --i) {
			while (a[i] > a[i + 1]) {
				ans_mn.emplace_back (make_pair (i, i + 1));
				a[i] += a[i + 1];
			}
		}
	}
	if (ok_mx && (int) ans_mx.size () <= 31) {
		int siz = ans_mx.size ();
		cout << siz << endl;
		for (int i = 0; i < siz; ++i) {
			cout << ans_mx[i].first << " " << ans_mx[i].second << endl;
		}
		return;
	}
	if (ok_mn && (int) ans_mn.size () <= 31) {
		int siz = ans_mn.size ();
		cout << siz << endl;
		for (int i = 0; i < siz; ++i) {
			cout << ans_mn[i].first << " " << ans_mn[i].second << endl;
		}
		return;
	}
	cout << 0 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}