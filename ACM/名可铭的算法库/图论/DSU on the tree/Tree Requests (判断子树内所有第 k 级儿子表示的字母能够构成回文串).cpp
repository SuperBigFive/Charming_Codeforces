#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 5e5 + 5;

int n, m, now_s;
char c[maxn];
int siz[maxn], ans[maxn];
int fa[maxn], son[maxn], dep[maxn];
int cnt1[maxn], cnt[maxn][30];
vector <pii> q[maxn];
vi adj[maxn];


void init () {for (int i = 1; i < maxn; ++i) ans[i] = 1;}

void dfs (int f, int u, int d) {
	siz[u] = 1;
	dep[u] = d;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs (u, it, d + 1);
		if (siz[it] > siz[son[u]]) son[u] = it;
	}
}

void cal (int f, int u, int val) {
	int num = c[u] - 'a' + 1;
	cnt[dep[u]][num] += val;
	if (cnt[dep[u]][num] & 1) ++cnt1[dep[u]];
	else --cnt1[dep[u]];
	for (auto it : adj[u]) {
		if (it == f || it == now_s) continue;
		cal (u, it, val);
	}
}

void dsu (int f, int u, int st) {
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		dsu (u, it, 0);
	}
	if (son[u]) dsu (u, son[u], 1), now_s = son[u];
	cal (f, u, 1);
	for (auto it : q[u]) {
		if (cnt1[it.se] > 1) ans[it.fi] = 0;
	}
	now_s = 0;
	if (!st) cal (f, u, -1);
}

void charming () {
	init ();
	scanf ("%lld%lld", &n, &m);
	int f;
	for (int i = 2; i <= n; ++i) {
		scanf ("%lld", &f);
		adj[f].emplace_back (i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf (" %c", &c[i]);
	}
	int v, h;
	for (int i = 1; i <= m; ++i) {
		scanf ("%lld%lld", &v, &h);
		q[v].emplace_back (make_pair (i, h));
	}
	dfs (0, 1, 1);
	dsu (0, 1, 1);
	for (int i = 1; i <= m; ++i) {
		if (ans[i]) puts ("Yes");
		else puts ("No");
	}
}

signed main () {
	charming ();
	return 0;
}