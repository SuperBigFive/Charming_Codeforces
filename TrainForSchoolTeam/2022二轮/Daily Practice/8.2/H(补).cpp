#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 1e5 + 5;
int read () {
	char ch = getchar ();
	bool flag = true;
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = false;
		ch = getchar ();
	}
	int k = ch - '0';
	while (ch = getchar (), ch <= '9' && ch >= '0') {
		k = (k << 1) + (k << 3);
		k += (ch - '0');
	}
	if (flag) return k;
	return -k;
}

struct edge {
	int u, v;
	int nxt;
	int c;
	bool operator < (const edge &a) const {
		return c < a.c;
	}
}ed[maxn << 2];
int n, m, q, tot_e, tot_p;
int pre[maxn << 1], val[maxn << 1], head[maxn << 1], lim[maxn << 1];
int fa[maxn << 1][32], limm[maxn << 1][32];

void init () {
	for (int i = 0; i < (maxn << 1); ++i) {
		pre[i] = i;
	}
	lim[0] = INT_MAX;
}

void add (int u, int v, int c) {
	ed[++tot_e].u = u;
	ed[tot_e].v = v;
	ed[tot_e].nxt = head[u];
	ed[tot_e].c = c;
	head[u] = tot_e;
}

int find (int x) {
	if (x == pre[x]) return x;
	return pre[x] = find (pre[x]);
}

void dfs1 (int f, int u) {
	fa[u][0] = f;
	for (int i = 1; i < 20; ++i) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	if (u <= n) return;
	for (int e = head[u]; e; e = ed[e].nxt) {
		if (ed[e].v == f) continue;
		dfs1 (u, ed[e].v);
	}
}

void dfs2 (int f, int u) {
	limm[u][0] = lim[f] - val[u];
	for (int i = 1; i < 20; ++i) {
		limm[u][i] = max (limm[u][i - 1], limm[fa[u][i - 1]][i - 1]);
	}
	if (u <= n) return;
	for (int e = head[u]; e; e = ed[e].nxt) {
		if (ed[e].v == f) continue;
		dfs2 (u, ed[e].v);
	}
}

int get_mmax (int pos, int value) {
	int tmp = pos;
	for (int i = 20; i >= 0; --i) {
		if (fa[tmp][i] && value >= limm[tmp][i])
		tmp = fa[tmp][i];
	}
	return val[tmp] + value;
}

void charming () {
	init ();
	cin >> n >> m >> q;
	tot_p = n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	int u, v, c;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> c;
		add (u, v, c);
	}
	sort (ed + 1, ed + 1 + tot_e);
	for (int i = 1; i <= tot_e; ++i) {
		int fx = find (ed[i].u), fy = find (ed[i].v);
		if (fx != fy) {
			val[++tot_p] = val[fx] + val[fy];
			pre[fx] = pre[fy] = tot_p;
			lim[tot_p] = ed[i].c;
			add (tot_p, fx, ed[i].c);
			add (tot_p, fy, ed[i].c);
		}
	}
	dfs1 (0, tot_p);
	dfs2 (0, tot_p);
	int pos, value;
	for (int i = 1; i <= q; ++i) {
		cin >> pos >> value;
		cout << get_mmax (pos, value) << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}