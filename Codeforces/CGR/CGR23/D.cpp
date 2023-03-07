#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n, k;
int s[maxn], f[maxn], g[maxn];
vector <int> adj[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		adj[i].clear ();
		s[i] = f[i] = g[i] = 0;
	}
}

void dfs (int cur, int num) {
	f[cur] = s[cur] * num, g[cur] = s[cur];
	if (!adj[cur].size ()) return;
	vector <int> son_g;
	int siz = adj[cur].size ();
	for (auto it : adj[cur]) {
		dfs (it, num / siz);
		f[cur] += f[it];
		son_g.emplace_back (g[it]);
	}
	sort (son_g.begin (), son_g.end (), greater <int> ());
	for (int i = 0; i < num % siz; ++i) {
		f[cur] += son_g[i];
	}
	if (num % siz) g[cur] += son_g[num % siz];
	else g[cur] += son_g[0];
}

void charming () {
	init ();
	cin >> n >> k;
	for (int i = 2, fa; i <= n; ++i) {
		cin >> fa;
		adj[fa].emplace_back (i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	dfs (1, k);
	cout << f[1] << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}