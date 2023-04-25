#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
mt19937 rnd (random_device {} ());
const int N = 5e6 + 5;
const int mod = 1e9 + 7;
const int P = rnd () % mod;

int t, n;
int f[N], ok[N];
vector <int> adj[N];

void init () {
	for (int i = 0; i <= n; ++i)
	f[i] = 0, adj[i].clear ();
}

int shift (int x) {
	x ^= P;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= P;
	return x;
}

void dfs (int fa, int u) {
	f[u] = 1;
	map <int, int> mp;
	map <int, int> id;
	for (auto &it : adj[u]) {
		if (it == fa) continue;
		dfs (u, it);
		mp[f[it]] += 1;
		id[f[it]] = it;
		f[u] += shift (f[it]);
	}
	bool flag = false;
	for (auto [val, cnt] : mp) {
		if (cnt & 1) {
			if (!flag) {ok[u] = ok[id[val]]; flag = true;}
			else {ok[u] = false; break;}
		}
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	for (int i = 1; i <= n; ++i) ok[i] = 1;
	dfs (0, 1);
	cout << (ok[1] ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}