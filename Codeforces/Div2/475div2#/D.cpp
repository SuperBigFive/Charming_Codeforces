#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	int rt;
	vector <int> p (n + 5), du (n + 5);
	vector <vector <int> > G (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];	
		if (p[i] == 0) rt = i;
		else du[p[i]] += 1, du[i] += 1, G[p[i]].emplace_back (i);
	}
	if (n == 1) return void (cout << "YES" << endl << 1 << endl);
	vector <int> q (n + 5), vis (n + 5), ans;
	int head = 1, tail = 0;
	for (int i = 1; i <= n; ++i) {
		if (i != rt && du[i] == 1) q[++tail] = i;
		vis[i] = du[i] - 1 + (i == rt), du[i] &= 1;
	}
	while (head <= tail) {
		int u = q[head++];
		if (du[u] == 0) du[p[u]] ^= 1, ans.emplace_back (u);
		vis[p[u]] -= 1;
		if (p[u] && vis[p[u]] == 0) q[++tail] = p[u];
	}
	
	auto dfs = [&] (auto && me, int u) -> void {
		vis[u] = 1, cout << u << endl;
		for (auto &v : G[u]) {
			if (vis[v]) continue;
			else me (me, v);
		}
	};
	
	if (du[rt] == 0) {
		cout << "YES" << endl;
		vis = vector <int> (n + 5);
		for (auto i : ans) dfs (dfs, i);
	}
	else cout << "NO" << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}