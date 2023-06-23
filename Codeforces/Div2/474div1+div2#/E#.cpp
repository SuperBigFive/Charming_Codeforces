#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	vector <vector <int> > G (n);
	for (int &ai : a) cin >> ai;
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		--u, --v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	int ans = 0;
	vector <int> siz (n);
	vector <pair <int, int> > cnt (n);
	
	auto DFS1 = [&] (auto && me, int f, int u) -> pair <int, int> {
		int cntPos = 0, cntNeg = 0;
		vector <array <int, 3> > d;
		for (int v : G[u]) {
			if (v == f) continue;
			auto [pos, neg] = me (me, u, v);
			d.emplace_back ((array <int, 3>) {v, pos, neg});
			cntPos += neg, cntNeg += pos;
		}
		++cntPos;
		siz[u] = cntPos + cntNeg;
		for (auto [v, neg, pos] : d) {
			ans = (ans + (pos - neg) * (n - siz[v]) * a[u]) % MOD;
		}
		return cnt[u] = make_pair (cntPos, cntNeg);
	};
	
	auto DFS2 = [&] (auto && me, int f, int u, int outPos, int outNeg) -> void {
		ans = (ans + siz[u] * (outPos - outNeg) * a[u]) % MOD;
		for (int v : G[u]) {
			if (v == f) continue;
			me (me, u, v, outNeg + (cnt[u].second - cnt[v].first),
			outPos + (cnt[u].first - cnt[v].second));
		}
	};
	
	DFS1 (DFS1, -1, 0);
	DFS2 (DFS2, -1, 0, 0, 0);
	for (int i = 0; i < n; ++i) ans = (ans + n * a[i]) % MOD;
	ans = ((ans % MOD) + MOD) % MOD;
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}