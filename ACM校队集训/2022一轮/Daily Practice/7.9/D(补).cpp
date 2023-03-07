#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 2e5 + 5;

int n, m, s, meet, meet_bel, tot1, tot2;
int bel[maxn];
int path_a[maxn], path_b[maxn];
bool ok;
bool vis[maxn];
vector <int> adj[maxn];

void dfs1 (int fa, int u) {
	int v;
	for (int i = 0; i < adj[u].size (); ++i) {
		v = adj[u][i];
		if (bel[v] == bel[u] || v == s || v == fa) continue;
		if (bel[v]) {
			ok = true;
			meet = v;
			meet_bel = bel[v] - 1;
			path_b[++tot2] = v;
			path_b[++tot2] = u;
			return;
		}
		if (!bel[v]) bel[v] = bel[u];
		dfs1 (u, v);
		if (ok) {
			path_b[++tot2] = u;
			return;
		}
	}
}

void dfs2 (int fa, int u, int cnt) {
	if (ok) return;
	path_a[cnt] = u;
	if (u == meet) {
		tot1 = 1;
		return;
	}
	int v;
	for (int i = 0; i < adj[u].size (); ++i) {
		v = adj[u][i];
		if (v == meet) {
			tot1 = cnt;
			ok = true;
			return;
		}
		if (vis[v] || v == s || v == fa) continue;
		vis[v] = true;
		dfs2 (u, v, cnt + 1);
		if (ok) return;
	}
}

void charming () {
	cin >> n >> m >> s;
	int u, v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		adj[u].push_back (v);
	}
	if (!(adj[s].size () - 1)) {
		cout << "Impossible" << endl;
		return;
	}
	for (int i = 0; i < adj[s].size (); ++i) {
		if (!bel[adj[s][i]]) {
			bel[adj[s][i]] = i + 1;
			dfs1 (0, adj[s][i]);
		}
		else {
			path_b[++tot2] = adj[s][i];
			meet = adj[s][i];
			meet_bel = bel[meet] - 1;
			ok = true;
			break;
		}
		if (ok) break;
	}
	if (!ok) {
		cout << "Impossible" << endl;
		return;
	}
	ok = false;
	path_a[1] = s;
	vis[adj[s][meet_bel]] = true;
	dfs2 (0, adj[s][meet_bel], 2);
	path_a[++tot1] = meet;
	cout << "Possible" << endl;
	cout << tot1 << endl;
	for (int i = 1; i <= tot1; ++i) {
		cout << path_a[i] << ' ';
	}
	cout << endl;
	path_b[++tot2] = s;
	cout << tot2 << endl;
	for (int i = tot2; i >= 1; --i) {
		cout << path_b[i] << ' ';
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}