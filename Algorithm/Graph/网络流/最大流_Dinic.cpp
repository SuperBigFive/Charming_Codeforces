#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Dinic {
	int n, m, s, t, tot;
	vector <int> cur, dep, from, to, nxt, head, cap;
	
	void AddEdge (int u, int v, int c) {
		from[tot] = u, to[tot] = v, nxt[tot] = head[u], head[u] = tot;
		cap[tot] = c, ++tot;
	}
	
	Dinic (int n, int m, int s, int t, vector <array <int, 3> > &edge) {
		this -> n = n, this -> m = m, this -> s = s, this -> t = t, tot = 0;
		from = to = nxt = cap = vector <int> (m << 1);
		cur = dep = head = vector <int> (n + 5, -1);
		for (auto [u, v, w] : edge) AddEdge (u, v, w), AddEdge (v, u, 0);
	}
	
	bool BFS () {
		fill (dep.begin (), dep.end (), -1);
		queue <int> q;
		q.push (s), dep[s] = 1;
		while (!q.empty ()) {
			int u = q.front ();
			q.pop ();
			if (u == t) continue;
			else {
				for (int i = head[u], v, c; ~i; i = nxt[i]) {
					v = to[i], c = cap[i];
					if (dep[v] != -1 || !c) continue;
					dep[v] = dep[u] + 1, q.push (v);
				}
			}
		}
		return dep[t] > -1;
	}
		
	int DFS (int u, int last) {
		if (u == t) return last;
		int now = last;
		for (int i = cur[u], v, c; ~i; i = nxt[i]) {
			cur[u] = nxt[i];
			v = to[i], c = cap[i];
			if (dep[v] == dep[u] + 1 && c) {
				int delta = DFS (v, min (last, c));
				now -= delta, cap[i] -= delta, cap[i ^ 1] += delta;
				if (!now) break;
			}
		}
		return last - now;
	}
	
	int MaxFlow () {
		int ans = 0;
		while (BFS ()) {
			for (int i = 1; i <= n; ++i) cur[i] = head[i];
			ans += DFS (s, LLONG_MAX);
		}
		return ans;
	}
};

int n, m, s, t;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> s >> t;
	map <array <int, 2>, int> edge;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		edge[{u, v}] += w;
	}
	vector <array <int, 3> > EDGE;
	for (auto &[link, w] : edge) EDGE.emplace_back ((array <int, 3>) {link[0], link[1], w});
	cout << Dinic (n, m, s, t, EDGE).MaxFlow () << endl;
}
	
signed main () {
	charming ();
	return 0;
}