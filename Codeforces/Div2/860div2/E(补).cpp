#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), nxt (n + 5), times (n + 5), st (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	auto dfs = [&] (auto && me, int id) {
		if (id + a[id] + 1 > n + 1) {
			nxt[id] = n + 1, times[id] = 1, st[id] = false;
			return;
		}
		else if (id + a[id] + 1 == n + 1) {
			nxt[id] = n + 1, times[id] = 1, st[id] = true;
			return;
		}
		else if (nxt[id + a[id] + 1]) {
			nxt[id] = id + a[id] + 1;
			times[id] = times[id + a[id] + 1] + 1;
			st[id] = st[id + a[id] + 1];
		}
		else {
			me (me, id + a[id] + 1);
			nxt[id] = id + a[id] + 1;
			times[id] = times[id + a[id] + 1] + 1;
			st[id] = st[id + a[id] + 1];
		}
	};
	
	vector <int> ans (n + 5);
	map <int, int> past;
	past[0] = 1;
	for (int i = n - 1; i >= 1; --i) {
		dfs (dfs, i + 1);
		if (times[i + 1] == a[i] && st[i + 1]) ans[i] = 0;
		else if (times[i + 1] == a[i] || st[i + 1] || past[a[i] - 1]) ans[i] = 1;
		else ans[i] = 2;
		past[times[i + 1]] |= st[i + 1];
	}
	for (int i = 1; i <= n - 1; ++i) cout << ans[i] << " \n"[i == n - 1];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}