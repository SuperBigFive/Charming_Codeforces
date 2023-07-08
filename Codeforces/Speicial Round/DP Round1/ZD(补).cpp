#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e3 + 5;
const int mod = 1e9 + 7;

int n, k, q;

inline add (int x, int y) {return (x + y) % mod;};
inline mul (int x, int y) {return (x * y) % mod;};

void init () {}

void charming () {
	init ();
	cin >> n >> k >> q;
	vector <int> a (n + 5);
	vector <vector <int> > dp1 (n + 5, vector <int> (k + 5));
	vector <vector <int> > dp2 (n + 5, vector <int> (k + 5));
	for (int i = 1; i <= n; ++i) cin >> a[i];

	auto dfs1 = [&] (auto && me, int i, int j) -> int {
		if (j == 0) return dp1[i][j] = 1;
		if (dp1[i][j]) return dp1[i][j];
		if (i < n) dp1[i][j] = add (dp1[i][j], me (me, i + 1, j - 1));
		if (i > 1) dp1[i][j] = add (dp1[i][j], me (me, i - 1, j - 1));
		return dp1[i][j];
	};
	auto dfs2 = [&] (auto && me, int i, int j) -> int {
		if (j == k) return dp2[i][j] = 1;
		if (dp2[i][j]) return dp2[i][j];
		if (i < n) dp2[i][j] = add (dp2[i][j], me (me, i + 1, j + 1));
		if (i > 1) dp2[i][j] = add (dp2[i][j], me (me, i - 1, j + 1));
		return dp2[i][j];
	};
	for (int i = 1; i <= n; ++i) 
	for (int j = 0; j <= k; ++j)
	dfs1 (dfs1, i, j), dfs2 (dfs2, i, j);
	vector <ll> coef (n + 5);
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j)
		coef[i] = add (coef[i], mul (dp1[i][j], dp2[i][j]));
		res = add (res, mul (a[i], coef[i]));
	}
	for (int i = 1, id, val; i <= q; ++i) {
		cin >> id >> val;
		res = add (res, mul (val - a[id], coef[id]));
		a[id] = val;
		cout << add (add (res, mod), mod) << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}