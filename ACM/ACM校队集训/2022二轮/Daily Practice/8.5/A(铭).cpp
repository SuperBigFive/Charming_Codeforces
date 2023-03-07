#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define int ull
#define vi vector <int>
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 2e5 + 5;

struct Edge{
	int u;
	int v;
	int w;
	bool operator < (const Edge &e) const {
		return w < e.w;
	}
}edge[maxm];
struct Used {
	int l, r;
	int w;
}edge_u[maxm];
int t, n, m, tot;
ull k1, k2;
int pre[maxn];

ull rand_edge () {
	ull k3 = k1, k4 = k2;
	k1 = k4;
	k3 ^= k3 << 23;
	k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
	return k2 + k4;
}

void get_edge () {
	cin >> n >> m >> k1 >> k2;
	for (int i = 1; i <= m; ++i) {
		edge[i].u = rand_edge () % n + 1;
		edge[i].v = rand_edge () % n + 1;
		edge[i].w = rand_edge ();
	}
}

void init () {
	tot = 0;
}

int find (int x) {
	if (x == pre[x]) return x;
	return pre[x] = find (pre[x]);
}

int dfs (int l, int r, int now, int num) {
	int res = 0;
	if (now > r) {
		if (num == r - l + 1) return 1;
		else return 0;
	}
	int u = edge[now].u, v = edge[now].v;
	int fu = find (u), fv = find (v);
	if (fu != fv) {
		pre[fv] = fu;
		res = (res + dfs (l, r, now + 1, num + 1)) % mod;
		pre[fv] = fv;
		pre[fu] = fu;
		res = (res + dfs (l, r, now + 1, num)) % mod;
	}
	return res;
}

void charming () {
	init ();
	get_edge ();
	sort  (edge + 1, edge + 1 + m);
	int u, v, fu, fv, cnt = 0;
	ll sum_w = 0;
	for (int i = 1; i <= n; ++i) {
		pre[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		u = edge[i].u, v = edge[i].v;
		fu = find (u), fv = find (v);
		if (fu != fv) {
			++cnt;
			pre[fv] = fu;
			sum_w = (sum_w + edge[i].w) % mod;
			if (edge[i].w == edge_u[tot].w) {
				++edge_u[tot].r;
			}
			else {
				edge_u[++tot].l = i;
				edge_u[tot].r = i;
				edge_u[tot].w = edge[i].w;
			}
		}
	}
	if (cnt != n - 1) {
		cout << 0 << endl;
		return;
	}
	ll ans = 1;
	int l, r;
	for (int i = 1; i <= tot; ++i) {
		l = edge_u[i].l, r = edge_u[i].r;
		for (int i = l; i <= r; ++i) {
			u = edge[i].u;
			v = edge[i].v;
			pre[u] = u, pre[v] = v;
		}
		ans = (ans * dfs (l, r, l, 0))% mod;
	}
	ans = (ans * sum_w) % mod;
	cout << ans << endl;
}

signed main () {
	scanf ("%lld", &t);
	while (t--) charming ();
	return 0;
}