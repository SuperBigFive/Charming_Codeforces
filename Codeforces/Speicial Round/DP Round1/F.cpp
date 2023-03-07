#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int LEN = 30;

int q;

void init () {}

void charming () {
	init ();
	cin >> q;
	for (int i = 1, u, v; i <= q; ++i) {
		cin >> u >> v;
		if (u > v) {
			cout << "NO" << endl;
			continue;
		}
		int cnt1 = 0, cnt2 = 0;
		vector <int> d1 (LEN), d2(LEN);
		for (int i = 0; i < LEN; ++i) {
			if (u >> i & 1) d1[i] = 1, ++cnt1;
			if (v >> i & 1) d2[i] = 1, ++cnt2;
		}
		if (cnt1 < cnt2) {
			cout << "NO" << endl;
			continue;
		}
		bool ok = false;
		int cnt = 0;
		for (int i = LEN - 1; i >= 0; --i) {
			if (d1[i] == d2[i]) continue;
			else if (!d1[i] && d2[i]) {
				ok = true;
				++cnt;
			}
			else {
				if (cnt > 0) --cnt;
				else if (!ok) break;
			}
		}
		cout << ((ok && cnt <= 0) || u == v ? "YES" : "NO") << endl;
	}
}

signed main () {
	charming ();
	return 0;	
}
