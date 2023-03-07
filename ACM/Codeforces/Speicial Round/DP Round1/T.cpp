#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, tot;
int ls[N << 5], rs[N << 5];

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	auto add = [&] (int num) -> void {
		int cur = 0;
		for (int i = 30; i >= 0; --i) {
			if ((num >> i) & 1) {
				if (!rs[cur]) rs[cur] = ++tot;
				cur = rs[cur];
			}
			else {
				if (!ls[cur]) ls[cur] = ++tot;
				cur = ls[cur];
			}
		}
	};
	for (auto &it : a) cin >> it, add (it);
	int res = 0;
	auto dfs = [&] (auto && me, int u, int cnt) -> void {
		int st = (ls[u] && rs[u]);
		if (ls[u]) me (me, ls[u], cnt + st);
		if (rs[u]) me (me, rs[u], cnt + st);
		res = max (res, cnt + st);
	};
	dfs (dfs, 0, 0);
	cout << n - res - 1 << endl;
}

signed main () {
	charming ();
	return 0;
}