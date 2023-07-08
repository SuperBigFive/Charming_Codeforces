#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct EdmondsKarp {
	int n, m, s, t, tot;
	vector <int> from, to, nxt, head, cap, vis, pre;
	
	void AddEdge (int u, int v, int c) {
		from[tot] = u, to[tot] = v, nxt[tot] = head[u], head[u] = tot;
		cap[tot] = c, ++tot;
	}
	
	EdmondsKarp (int n, int m, int s, int t, vector <array <int, 3> > &edge) {
		this -> n = n, this -> m = m, this -> s = s, this -> t = t, tot = 0;
		from = to = nxt = cap = vector <int> (m << 1);
		head = vector <int> (m << 1, -1);
		vis = pre = vector <int> (n + 5);
		for (auto &[u, v, w] : edge) {
			AddEdge (u, v, w);
			AddEdge (v, u, 0);
		}
	}
	
	int DFS (int u, int mnc, int id) {
		if (u == t) return mnc;
		vis[u] = id;
		for (int i = head[u], v, c; ~i; i = nxt[i]) {
			v = to[i], c = cap[i];
			if (vis[v] == id || !c) continue;
			else {
				int nans = DFS (v, min (mnc, c), id);
				if (nans > 0) {
					cap[i] -= nans, cap[i ^ 1] += nans;
					return nans;
				}
			}
		}
		return 0;
	}
	
	int Update (int delta) {
		int u = t, id;
		while (u != s) {
			id = pre[u];
			cap[id] -= delta, cap[id ^ 1] += delta;
			u = from[id];
		}
		return delta;
	}
	
	int BFS (int id) {
		queue <pair <int, int> > q;
		q.push (make_pair (s, LLONG_MAX));
		vis[s] = id;
		while (!q.empty ()) {
			auto [u, mnc] = q.front ();
			q.pop ();
			for (int i = head[u], v, c, nmxf; ~i; i = nxt[i]) {
				v = to[i], c = cap[i];
				if (vis[v] == id || !c) continue;
				vis[v] = id;
				nmxf = min (mnc, c);
				q.push (make_pair (v, nmxf));
				pre[v] = i;
				if (v == t) return Update (nmxf);
			}
		}
		return 0;
	}
	
	int MaxFlow () {
		int ans = 0, nans, cnt = 0;
		while (true) {
			nans = BFS (++cnt);
			//nans = DFS (s, INT_MAX, ++cnt);
			if (nans == 0) break;
			else ans += nans;
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
	vector <array <int, 3> > EDGE;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		edge[{u, v}] += w;
	}
	for (auto [link, w] : edge) {
		EDGE.emplace_back ((array <int, 3>) {link[0], link[1], w});
	}
	cout << EdmondsKarp (n, m, s, t, EDGE).MaxFlow () << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}