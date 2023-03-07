#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
using namespace std;
const int maxn = 2e5 + 5;

struct Edge {
	int to;
	int c;
	int nxt;
}edge[maxn];
int t, n, m, lim_l, lim_t, tot;
int head[maxn], dep[maxn], cur[maxn];
int pro[maxn], pay[maxn], tim[maxn];
bool shop[maxn], plant[maxn];
vi match[maxn];

void init () {
	for (int i = 1; i < maxn; ++i) match[i].clear ();
}

void add (int u, int v, int c) {
	edge[tot].to = v;
	edge[tot].c = c;
	edge[tot].nxt = head[u];
	head[u] = tot++;
}

int build_flow (int S, int T) {
	fill_n (head, n + m + 5, -1);
	for (int i = 0; i <= tot; ++i) 
	edge[i].nxt = edge[i].to = edge[i].c = 0;
	tot = 0;
	fill_n (shop + 1, m, false);
	fill_n (plant + 1, n, false);
	for (int i = 1; i <= n; ++i) {
		if (tim[i] > lim_t) continue;
		plant[i] = true;
		add (m + i, T, pay[i]);
		add (T, m + i, 0);
	}
	int sum = 0;
	for (int i = 1, ok; i <= m; ++i) {
		ok = 1;
		for (auto it : match[i]) if (!plant[it]) {
			ok = 0;
			break;
		}
		if (!ok) continue;
		sum += pro[i];
		add (S, i, pro[i]);
		add (i, S, 0);
		for (auto it : match[i]) {
			add (i, m + it, INT_MAX);
			add (m + it, i, 0);
		}
	}
	return sum;
}

bool bfs (int S, int T) {
	fill_n (dep, n + m + 5, -1);
	queue <int> q;
	q.push (S), dep[S] = 0;
	int now, v;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = head[now]; i != -1; i = edge[i].nxt) {
			v = edge[i].to;
			if (dep[v] != -1 || !edge[i].c) continue;
			dep[v] = dep[now] + 1;
			q.push (v);
		}
	}
	return dep[T] != -1;
}

int dfs (int u, int T, int flo) {
	if (u == T) return flo;
	int n_flo = flo;
	for (int i = cur[u], v; i != -1; i = edge[i].nxt) {
		cur[u] = edge[i].nxt;
		v = edge[i].to;
		if (dep[v] != dep[u] + 1 || !edge[i].c) continue;
		int d = dfs (v, T, min (n_flo, edge[i].c));
		edge[i].c -= d, edge[i ^ 1].c += d;
		n_flo -= d;
		if (!n_flo) break;
	}
	return flo - n_flo;
}

int dinic (int S, int T) {
	int res = 0;
	while (bfs (S, T)) {
		for (int i = 0; i <= T; ++i)
		cur[i] = head[i];
		res += dfs (S, T, INT_MAX);
	}
	return res;
}

void charming (int cnt) {
	init ();
	cin >> n >> m >> lim_l;
	for (int i = 1; i <= n; ++i) {
		cin >> pay[i] >> tim[i];
	}
	for (int i = 1, k; i <= m; ++i) {
		cin >> pro[i] >> k;
		for (int j = 1, tmp; j <= k; ++j) {
			cin >> tmp;
			match[i].emplace_back (tmp);
		}
	}
	int ans_t = INT_MAX, ans_l = -1, sum;
	for (int i = 1; i <= n; ++i) {
		if (tim[i] > ans_t) continue;
		lim_t = tim[i];
		sum = build_flow (0, n + m + 1) - dinic (0, n + m + 1);
		if (sum >= lim_l) {
			if (ans_t == lim_t) ans_l = max (ans_l, sum);
			else ans_l = sum;
			ans_t = lim_t;
		}
	}
	cout << "Case #" << cnt << ": ";
	if (ans_t == INT_MAX) cout << "impossible" << endl;
	else cout << ans_t << ' ' << ans_l << endl;
}

signed main () {
	cin >> t;
	for (int i = 1; i <= t; ++i)
	charming (i);
	return 0;
}