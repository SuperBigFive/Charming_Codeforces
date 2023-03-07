#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int t, m;

void init () {}

void charming () {
	init ();
	cin >> m;
	bool ok = true;
	int res = 0;
	vector <int> p(m + 1);
	vector <int> q(m + 1);
	for (int i = 1; i <= m; ++i) cin >> p[i];
	int w = 2;
	while (w <= m) {
		q = p;
		for (int i = 1; i <= m; i += w) {
			sort (q.begin () + i, q.begin () + i + w);
			for (int j = i; j < i + w; ++j) {
				if (q[j] - j != q[i] - i) {
					cout << -1 << endl;
					return;
				}
			}
		}
		w <<= 1;
	}
	vector <int> key;
	while (m > 1) {
		q = p;
		for (int i = 1; i <= m; i += 2) {
			if (q[i] > q[i + 1]) ++res;
			p[i / 2 + 1] = min (q[i], q[i + 1]);
		}
		m >>= 1;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}