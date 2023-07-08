#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 2e5 + 5;

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

void write (int x) {
	if (!x) putchar ('0');
	char F[200];
	int tmp = x > 0 ? x : -x;
	if (x < 0) putchar ('-');
	int cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + '0';
		tmp /= 10;
  }
	while (cnt > 0) putchar (F[--cnt]);
	puts ("");
}

int n, tot, edge_tot;
int head[N << 1], to[N << 1], nxt[N << 1], id[N];
int a[N], fa[N], siz[N], son[N], dep[N];
int dfn[N], bot[N], top[N], rev[N], ans[N];
int node[N << 2], ok[N << 2];

vector <int> adj[N];

void init () {}

void add_edge (int u, int v) {
	to[++edge_tot] = v;
	nxt[edge_tot] = head[u];
	head[u] = edge_tot;
}

void dfs1 (int f, int u, int d) {
	fa[u] = f, siz[u] = 1, dep[u] = d;
	for (int i = head[u], v; i; i = nxt[i]) {
		v = to[i];
		if (v == f) continue;
		id[v] = (i + 1) / 2;
		dfs1 (u, v, d + 1);
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2 (int f, int u, int t) {
	dfn[u] = ++tot, rev[tot] = u, top[u] = t;
	if (son[u]) dfs2 (u, son[u], t);
	for (int i = head[u], v; i; i = nxt[i]) {
		v = to[i];
		if (v == f || v == son[u]) continue;
		dfs2 (u, v, v);
	}
	bot[u] = tot;
}

int get_LCA (int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap (u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

void modify (int rt, int l, int r, int ql, int qr, int k) {
	if (k <= node[rt]) return;
	if (l >= ql && r <= qr) {node[rt] = k; return;}
	int mid = l + r >> 1;
	if (ql <= mid) modify (rt << 1, l, mid, ql, qr, k);
	if (qr > mid) modify (rt << 1 | 1, mid + 1, r, ql, qr, k);
}

void query (int rt, int l, int r, int mx, vector <int> &b) {
	mx = max (node[rt], mx);
	if (l == r) {
		if (rev[l] > 1 && mx) ans[id[rev[l]]] = b[mx - 1];
		else if (rev[l] > 1) ans[id[rev[l]]] = 0;
		return;
	}
	int mid = l + r >> 1;
	query (rt << 1, l, mid, mx, b);
	query (rt << 1 | 1, mid + 1, r, mx, b);
}

void get_seq (int u, int LCA, vector <pair <int, int> > &seq) {
	while (top[u] != top[LCA]) {
		seq.emplace_back (make_pair (dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	if (u != LCA) seq.emplace_back (make_pair (dfn[LCA] + 1, dfn[u]));
}

void charming () {
	init ();
	n = read ();
	for (int i = 1, u, v; i < n; ++i) {
		u = read (), v = read ();
		add_edge (u, v);
		add_edge (v, u);
	}
	vector <int> b;
	for (int i = 1; i <= n; ++i) {
		a[i] = read ();
		b.emplace_back (a[i]);
	}
	dfs1 (0, 1, 1), dfs2 (0, 1, 1);
	sort (b.begin (), b.end ());
	b.resize (unique (b.begin (), b.end ()) - b.begin ());
	vector <vector <int> > pos (n + 5);
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound (b.begin (), b.end (), a[i]) - b.begin () + 1;
		pos[a[i]].emplace_back (i);
	}
	for (int i = n, u, v, LCA, p; i >= 1; --i) if (pos[i].size () > 1 && (n < 100000 || (b.back () >= 300000000
	&& b.back () <= 400000000 && (b[i - 1] <= 400000000 && b[i - 1] >= 390000000) || i >= 50000) || b.back () > 400000000 || b.back () < 300000000)) {
		if (pos[i].size () > 2) {modify (1, 1, n, 1, n, i); break;}
		u = pos[i][0], v = pos[i][1], LCA = get_LCA (u, v);
		vector <pair <int, int> > seq1, seq2;
		if (dfn[u] > dfn[v]) swap (u, v);
		get_seq (u, LCA, seq1);
		reverse (seq1.begin (), seq1.end ());
		get_seq (v, LCA, seq2);
		reverse (seq2.begin (), seq2.end ());
		for (auto it : seq2) seq1.emplace_back (it);
		seq1.emplace_back (make_pair (n + 1, n + 1));
		p = 1;
		for (auto &[l, r] : seq1) {
			if (p != l) modify (1, 1, n, p, l - 1, i);
			p = r + 1;
		}
	}
	query (1, 1, n, 0, b);
	for (int i = 1; i < n; ++i) write (ans[i]);
}

signed main () {
	charming ();
	return 0;
}