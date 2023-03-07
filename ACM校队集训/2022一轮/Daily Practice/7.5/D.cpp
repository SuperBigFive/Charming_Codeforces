#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int n, k, mmax = -1;
int sz[maxn];
int f[maxn];
int dep[maxn];
ll val[maxn];
vector <int> node[maxn];

init () {}

void dfs (int fa, int u, int depth) {
	dep[u] = depth;
	f[u] = fa;
	mmax = max (mmax, dep[u]);
	int v;
	for (int i = 0; i < node[u].size (); ++i) {
		v = node[u][i];
		if (v == fa) continue;
		dfs (u, v, depth + 1);
		sz[u] += sz[v] + 1;
	}
}

void charming () {
	init ();
	cin >> n >> k;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		node[u].push_back (v);
		node[v].push_back (u);
	}
	dfs (0, 1, 1);
	for (int i = 1; i <= n; ++i) val[i] = dep[i] - 1 - sz[i];
	sort (val + 1, val + 1 + n);
	ll ans = 0;
	for (int i = n; k; --i) {
		--k;
		ans += val[i];
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming (); 
}
