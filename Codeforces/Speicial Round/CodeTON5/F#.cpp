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
	vector <vector <int> > G (n);
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		--u, --v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	vector <int> ans (n + 1, INT_MAX);
	vector <int> dep (n);
	queue <int> q;
	for (int rt = 0, u, sum; rt < n; ++rt) {
		dep = vector <int> (n, -1);
		q.push (rt), dep[rt] = 0;
		sum = 0;
		for (int i = 1; i <= n; ++i) {
			u = q.front ();
			q.pop ();
			sum += 2 * dep[u];
			for (int v : G[u]) {
				if (dep[v] <= -1) {
					dep[v] = dep[u] + 1;
					q.push (v);
				}
			}
			ans[i] = min (ans[i], sum);
		}
	}
	ans[0] = 0;
	for (int k = 0; k <= n; ++k) cout << (n - 1) * k - ans[k] << " \n"[k == n];
}

signed main () {
	charming ();
	return 0;
}