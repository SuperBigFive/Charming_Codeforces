#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
int fa[maxn], stk[maxn];
bool vis[maxn];
vector <int> adj[maxn];

void init () {}

void charming () {
	init ();
	scanf ("%d%d", &n, &m);
	for (int i = 2, f; i <= n; ++i) {
		scanf ("%d", &fa[i]);
		adj[fa[i]].emplace_back (i);
	}
	for (int i = 1, siz; i <= m; ++i) {
		scanf ("%d", &siz);
		int res = 0, tail = 0;
		vector <int> node (siz);
		for (auto &it : node) scanf ("%d", &it);
		sort (node.begin (), node.end ());
		for (auto it : node) {
			res += adj[it].size () + 1;
			stk[++tail] = it;
			if (vis[fa[it]]) res -= 2;
			vis[it] = true;
		}
		printf ("%d\n", res);
		while (tail > 0) vis[stk[tail--]] = false;
	}
}

signed main () {
	charming ();
	return 0;
}