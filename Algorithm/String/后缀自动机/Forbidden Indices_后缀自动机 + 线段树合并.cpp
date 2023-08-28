#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int n, last, tot1, tot2;
int root[maxn << 1];
int len[maxn << 1], link[maxn << 1];
int node[maxn * 90], ls[maxn * 90], rs[maxn * 90];
char s[maxn], t[maxn];
bool vis[maxn];
vector <int> adj[maxn << 1];
map <char, int> nxt[maxn << 1];

void init () {
	last = tot1 = tot2 = 0;
	len[0] = 0, link[0] = -1;
}

int modify (int l, int r, int pos) {
	int now = ++tot1;
	if (l == r) {
		if (!vis[pos]) ++node[now];
		return now;
	}
	int mid = l + r >> 1;
	if (pos <= mid) ls[now] = modify (l, mid, pos);
	else rs[now] = modify (mid + 1, r, pos);
	node[now] = node[ls[now]] + node[rs[now]];
	return now;
}

int merge (int x, int y, int l, int r) {
	if (!x || !y) return x + y;
	int now = ++tot1;
	if (l == r) {
		node[now] = node[x] + node[y];
		return now;
	}
	int mid = l + r >> 1;
	ls[now] = merge (ls[x], ls[y], l, mid);
	rs[now] = merge (rs[x], rs[y], mid + 1, r);
	node[now] = node[ls[now]] + node[rs[now]];
	return now;
}

void dfs (int f, int u) {
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs (u, it);
		root[u] = merge (root[u], root[it], 1, n);
	}
}

void sam_ins (int id, char ch) {
	int cur = ++tot2, p = last;
	len[cur] = len[last] + 1;
	while (p != -1 && !nxt[p].count (ch)) {
		nxt[p][ch] = cur;
		p = link[p];
	}
	if (p == -1) link[cur] = 0;
	else {
		int q = nxt[p][ch];
		if (len[p] + 1 == len[q]) link[cur] = q;
		else {
			int clone = ++tot2;
			root[clone] = ++tot1;
			len[clone] = len[p] + 1;
			link[clone] = link[q];	
			nxt[clone] = nxt[q];
			while (p != -1 && nxt[p][ch] == q) {
				nxt[p][ch] = clone;
				p = link[p];
			}
			link[q] = link[cur] = clone;
		}
	}
	last = cur;
	root[cur] = modify (1, n, id);
}

void charming () {
	init ();
	cin >> n;
	cin >> s + 1;
	cin >> t + 1;
	for (int i = 1; i <= n; ++i) if (t[i] == '1') {
		vis[i] = true;
	}
	int len_s = strlen (s + 1);
	for (int i = 1; i <= len_s; ++i) sam_ins (i, s[i]);
	for (int i = 1; i <= tot2; ++i) {
		adj[link[i]].emplace_back (i);
	}
	dfs (-1, 0);
	ll res = 0;
	for (int i = 1; i <= tot2; ++i) {
		res = max (1ll * res, 1ll * len[i] * node[root[i]]);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}