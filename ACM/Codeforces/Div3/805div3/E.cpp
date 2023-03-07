#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 4e5 + 5;

int t, n, okk = 0;
int cnt[maxn];
int times[maxn];
vector <int> adj[maxn];
bool ok;
bool vis[maxn];

void init () {
	for (int i = 1; i <= n; ++i) okk = 0, cnt[i] = 0, adj[i].clear (), vis[i] = false, times[maxn] = 0;
}

void dfs (int fa, int u, int cnt) {
	if (okk) return;
	if (cnt >= n) {
		okk = 1;
		cout << "YES" << endl;
		return;
	}
	times[u] = cnt;
	int tmp1 = adj[u][0], tmp2 = adj[u][1];
	int tmp = tmp1 == fa ? tmp2 : tmp1;
	if (vis[tmp]) {
		if ((cnt + times[tmp]) & 1) {
			int v = 1;
			while (vis[v]) ++v;
			vis[v] = true;
			dfs (0, v, cnt + 1);
			if (okk) return;
		}
		else {
			okk = -1;
			cout << "NO" << endl;
			return;
		}
	}
	else vis[tmp] = true, dfs (u, tmp, cnt + 1);
}

void charming () {
	init ();
	cin >> n;
	int u, v;
	ok = true;
	for (int i = 1; i <= n; ++i) {
		cin >> u >> v;
		adj[u].push_back (v);
		adj[v].push_back (u);
		++cnt[u], ++cnt[v];
		if (cnt[u] > 2 || cnt[v] > 2 || u == v) ok = false;
	}
	if (!ok) {
		cout << "NO" << endl;
		return;
	}
	vis[1] = true;
	dfs (1, 1, 1);
	/*int last = 1;
	tmp1 = adj[1][0], tmp2 = adj[1][1];
	int cnt = 1;
	vis[1] = true;
	while (cnt < n) {
		u = adj[tmp1][0], v = adj[tmp1][1];
		if (last == u) {
			if (!vis[v]) last = tmp1, tmp1 = v, vis[v] = true;
			else {
				cout << "NO" << endl;
				return;
			}
		}
		else {
			if (!vis[u]) last = tmp2, tmp2 = u, vis[u] = true;
			else {
				cout << "NO" << endl;
				return;
			}
		}
	}*/
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}