#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int, int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

struct Edge {
	int to;
	int c;
	int nxt;
}edge[maxn];
int n, m, s, t, cnt;
int head[maxn], cur[maxn], dep[maxn];

void init () {
	fill_n (head, maxn, -1);
	fill_n (cur, maxn, 0);
} 

void add (int u, int v, int c) {
	edge[cnt].to = v;
	edge[cnt].c = c;
	edge[cnt].nxt = head[u];
	head[u] = cnt++;
}

bool bfs (int s, int t) {
	fill_n (dep, n + m, -1);
	queue <int> q;
	q.push (s), dep[s] = 0;
	int now, v;
	while (!q.empty ()) {
		now = q.front (), q.pop ();
		for (int i = head[now]; i != -1; i = edge[i].nxt) {
			v = edge[i].to;
			if (dep[v] == -1 && edge[i].c) {
				dep[v] = dep[now] + 1;
				q.push (v);
			}	
		}
	}
	return dep[t] != -1;
}

int dfs (int u, int t, int flo) {
	if (u == t) return flo;
	int n_flo = flo;
	for (int i = cur[u], v; i != -1; i = edge[i].nxt) {
		cur[u] = edge[i].nxt;
		v = edge[i].to;
		if (dep[u] + 1 == dep[v] && edge[i].c) {
			int d = dfs (v, t, min (n_flo, edge[i].c));
			edge[i].c -= d, edge[i ^ 1].c += d;
			n_flo -= d;
			if (!n_flo) break;
		}
	}
	return flo - n_flo;
}

int dinic (int s, int t) {
	int res = 0;
	while (bfs (s, t)){
		for (int i = 1; i <= n; ++i)
		cur[i] = head[i];
		res += dfs (s, t, INT_MAX);
	}
	return res;
}

void charming () {
	init ();
	cin >> n >> m >> s >> t;
	int a, b, c;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b >> c;
		add (a, b, c);
		add (b, a, 0);
	}
	int res = dinic (s, t);
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}