#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 4e5 + 5;

int n;
int a[maxn], dep[maxn];
vector <int> adj[maxn];

void init () {}

void dfs (int u) {
	for (auto it : adj[u]) {
		dep[it] = dep[u] + 1;
		dfs (it);
	}
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) 
	cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		adj[a[i]].emplace_back (2 * i);
		adj[a[i]].emplace_back (2 * i + 1);
	}
	dep[1] = 0, dfs (1);
	for (int i = 1; i <= 2 * n + 1; ++i) {
		cout << dep[i] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}