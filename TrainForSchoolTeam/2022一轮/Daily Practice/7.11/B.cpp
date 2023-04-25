#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll 
#define ld long double
using namespace std;
const int maxn = 2e5 + 5;

int n, m, k;
int pre[maxn], siz[maxn], key[maxn];
bool vis[maxn];
set <int> component;
vector <int> adj[maxn];

void init () {
	for (int i = 1; i <= n; ++i) pre[i] = i;
}

void dfs (int fa, int u, int bel) {
	int v;
	for (int i = 0; i < adj[u].size (); ++i) {
		v = adj[u][i];
		if (!vis[v] && v != fa) {
			vis[v] = true;
			pre[v] = bel;
			++siz[key[bel]];
			dfs (u, v, bel);
		}
	}
}

void charming () {
	init ();
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> key[i];
		siz[key[i]] = 1;
		vis[key[i]] = true;
	}
	int u, v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		adj[u].push_back (v);
		adj[v].push_back (u);
	}
	for (int i = 1; i <= k; ++i) {
		dfs (0, key[i], i);
	}
	ll ans = 0, mmax = -1;
	for (int i = 1; i <= k; ++i) {
		ans += (siz[key[i]] - 1) * siz[key[i]] / 2;
		if (siz[key[i]] > mmax) mmax = siz[key[i]];
	}
	ans -= m;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) ans += mmax, ++mmax;
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}