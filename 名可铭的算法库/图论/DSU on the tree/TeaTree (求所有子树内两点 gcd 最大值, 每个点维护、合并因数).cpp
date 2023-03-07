#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pb push_back 
using namespace std;
const int maxn = 1e5 + 5;

int n;
int val[maxn], res[maxn];
vi adj[maxn], fac[maxn];
set <int> fac_u[maxn];

void get_fac () {
	for (int i = 1; i < maxn; ++i) {
		for (int j = i; j < maxn; j += i) {
			fac[j].pb (i);
		}
	}
}

void init () {
	for (int i = 1; i <= n; ++i) res[i] = -1;
}

int merge (int u, int v) {
	int res_tmp = -1;
	if (fac_u[u]. size() < fac_u[v].size ()) swap (fac_u[u], fac_u[v]);
	for (auto it : fac_u[v]) {
		if (fac_u[u].count (it)) {
			res_tmp = max (res_tmp, it);
		}
		else fac_u[u].insert (it);
	}
	fac_u[v].clear ();
	return res_tmp;
}

void dfs (int u) {
	for (auto it : adj[u]) {
		dfs (it);
		res[u] = max (res[u], merge (u, it));
	}
	for (auto it : fac[val[u]]) {
		if (fac_u[u].count (it)) {
			res[u] = max (res[u], it);
		}
		else fac_u[u].insert (it);
	}
}

void charming () {
	scanf ("%lld", &n);
	init ();
	int fa;
	for (int i = 2; i <= n; ++i) {
		scanf ("%lld", &fa);
		adj[fa].pb (i);
	}
	for (int i = 1; i <= n; ++i) scanf ("%lld", &val[i]);
	dfs (1);
	for (int i = 1; i <= n; ++i) {
		printf ("%lld\n", res[i]);
	}
}

signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	get_fac ();
	charming ();
	return 0;
}