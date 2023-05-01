#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Dijkstra {
	int n, s;
	vector <int> dis, vis;
	vector <vector <pair <int, int> > > G;
	
	Dijkstra (int n, int s, vector <vector <pair <int, int> > > G) {
		this -> n = n, this -> s = s, this -> G = G;
		dis = vector <int> (n + 5, INT_MAX);
		vis = vector <int> (n + 5);
	}
	
	vector <int> Get_dis () {
		dis[s] = 0;
		priority_queue <pair <int, int>, vector <pair <int, int> >,
		greater <pair <int, int> > > pq;
		pq.push (make_pair (0, s));
		while (!pq.empty ()) {
			auto [udis, u] = pq.top ();
			pq.pop ();
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto &[v, w] : G[u]) {
				if (vis[v]) continue;
				else if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					pq.push (make_pair (dis[v], v));
				}
			}
		}
		return dis;
	}
};

struct Node {
	int id, g, h;
	friend bool operator < (Node x, Node y) {
		return x.g + x.h > y.g + y.h;
	}
};

struct Astar {
	int n, s, t;
	vector <int> dis, kdis;
	vector <vector <pair <int, int> > > G;
	
	Astar (int n, int s, int t, vector <int> dis, vector <vector <pair <int, int> > > G) {
		this -> n = n, this -> s = s, this -> t = t;
		this -> dis = dis, this -> G = G;
	}
	
	int Get_kdis (int k) {
		priority_queue <Node> pq;
		for (auto &[v, w] : G[s]) pq.push ((Node) {v, w, dis[v]});
		while (k) {
			Node cur = pq.top ();
			pq.pop ();
			if (cur.id == t) kdis.emplace_back (cur.g + cur.h), --k;
			for (auto &[v, w] : G[cur.id]) pq.push ((Node) {v, w + cur.g, dis[v]});
		}
		return kdis.back ();
	}
	
};

int n, m, k;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> k;
	vector <vector <pair <int, int> > > G (n + 5), revG (n + 5);
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		G[u].emplace_back (make_pair (v, w));
		revG[v].emplace_back (make_pair (u, w));
	}
	cout << Astar (n, 1, n, Dijkstra (n, n, revG).Get_dis (), G).Get_kdis (k) << endl;
}

signed main () {
	charming ();
	return 0;
}