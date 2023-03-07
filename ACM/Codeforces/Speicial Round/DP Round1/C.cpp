#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> cnt (n + 1);
	for (int i = 1, tim; i <= n; ++i)
	cin >> tim, ++cnt[tim];
	vector <int> out (n << 1);
	auto force = [&] (vector <int> &out, 
	vector <int> cnt) -> int {
		int res = 0, p = 0;
		for (int i = 1; i < n << 1; ++i) {
			while (cnt[p] <= 0) ++p;
			if (out[i]) {
				res += abs (i - p);
				--cnt[p];
			}
		}
		return res;
	};
	int res = 0;
	for (int i = 1; i <= n; ++i) if (cnt[i]) {
		int mn = INT_MAX;
		vector <int> nxt_out;
		for (int j = 1; j < n << 1; ++j) {
			vector <int> nout = out;
			int cnt_out = 0;
			for (int k = j; k < n << 1 && cnt_out < cnt[i]; ++k) {
				if (nout[k]) continue;
				else nout[k] = 1, ++cnt_out;
			}
			if (cnt_out < cnt[i]) continue;
			int val = force (nout, cnt);
			if (val < mn) {
				mn = val;
				nxt_out = nout;
			}
		}
		out = nxt_out;
	}
	cout << force (out, cnt) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}