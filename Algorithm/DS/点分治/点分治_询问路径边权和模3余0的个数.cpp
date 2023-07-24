#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, p;
int siz[N], vis[N];

void Get_root (int f, int u, int remain, int &mx, int &rt,
vector <vector <pair <int, int> > > &G) {
	int mx_siz = -1, son_siz;
	siz[u] = 1;
	for (auto [v, w] : G[u]) {
		if (v == f || vis[v]) continue;
		Get_root (u, v, remain, mx, rt, G);
		son_siz = siz[v];
		siz[u] += son_siz, mx_siz = max (mx_siz, son_siz);
	}
	mx_siz = max (mx_siz, remain - siz[u]);
	if (mx_siz < mx) mx = mx_siz, rt = u;
}

void DFS (int f, int u, int val, vector <int> &cnt, vector <int> &ncnt,
vector <vector <pair <int, int> > > &G) {
	siz[u] = 1;
	++ncnt[val % 3];
	int target = (((3 - val) % 3) + 3) % 3;
	p += cnt[target];
	for (auto [v, w] : G[u]) {
		if (v == f || vis[v]) continue;
		DFS (u, v, (val + w) % 3, cnt, ncnt, G);
		siz[u] += siz[v];
	}
}

void Calc (int u, vector <vector <pair <int, int> > > &G) {
	siz[u] = 1;
	vector <int> cnt (3);
	for (auto [v, w] : G[u]) {
		if (vis[v]) continue;
		vector <int> ncnt (3);
		DFS (u, v, w % 3, cnt, ncnt, G);
		for (int i = 0; i < 3; ++i) cnt[i] += ncnt[i];
		siz[u] += siz[v];
	}
	p += cnt[0] + 1;
}

void Divide (int u, vector <vector <pair <int, int> > > &G) {
	vis[u] = 1;
	Calc (u, G);
	for (auto [v, w] : G[u]) {
		if (vis[v]) continue;
		int mx = INT_MAX, rt = -1;
		Get_root (0, v, siz[v], mx, rt, G);
		Divide (rt, G);
	}
}

void init () {p = 0;}

void charming () {
	init ();
	cin >> n;
	vector <vector <pair <int, int> > > G (n + 5);
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		G[u].emplace_back (make_pair (v, w));
		G[v].emplace_back (make_pair (u, w));
	}
	int mx = INT_MAX, rt = -1;
	Get_root (0, 1, n, mx, rt, G);
	Divide (rt, G);
	p = p * 2 - n;
	ll q = n * n, GCD = __gcd (p, q);
	p /= GCD, q /= GCD;
	cout << p << "/" << q << endl;
}

signed main () {
	charming ();
	return 0;
}