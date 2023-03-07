#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, x, y, tail;
int stk[maxn];
vector <int> adj[maxn];

void init () {}

void dfs (int f, int u) {
	if (u == y) {
		for (int i = 1; i <= tail; ++i)
		cout << stk[i] << " \n"[i == tail];
		exit (0);
	}
	for (auto it : adj[u]) {
		if (it == f) continue;
		stk[++tail] = it;
		dfs (u, it);
		tail--;
	}
}


void charming () {
	cin >> n >> x >> y;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);	
	}
	stk[++tail] = x;
	dfs (0, x);
}

signed main () {
	charming ();
	return 0;
}