#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Dijkstra {
	int n, s;
	vector <int> dis, vis;
	vector <pair <int, int> > pre;
	vector <vector <array <int, 3> > > G;
	
	Dijkstra (int n, int s, vector <vector <array <int, 3> > > &G) {
		this -> n = n, this -> s = s;
		this -> G = G;
		dis = vector <int> (n + 5, INT_MAX);
		vis = vector <int> (n + 5);
		pre = vector <pair <int, int> > (n + 5);
	}
	
	pair <vector <int>, vector <pair <int, int> > > Get_dis () {
		priority_queue <pair <int, int>, vector <pair <int, int> >,
		greater <pair <int, int> > > pq;
		pq.push (make_pair (0, s));
		dis[s] = 0, vis[s] = true;
		while (!pq.empty ()) {
			auto [udis, u] = pq.top ();
			pq.pop (), vis[u] = true;
			for (auto &[v, w, id] : G[u]) {
				if (vis[v]) continue;
				else if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					pre[v].first = id, pre[v].second = u;
					pq.push (make_pair (dis[v], v));
				}
			}
		}
		return make_pair (dis, pre);
	}
};

struct Node {
	int tail, dis;
	friend bool operator < (Node x, Node y) {
		return x.dis > y.dis;
	}
};

struct LeftistTree {
	int n, cnt;
	vector <Node> node;
	vector <int> dist, root;
	vector <array <int, 2> > ch;
	
	LeftistTree () {}
	LeftistTree (int n) {
		this -> n = n, cnt = 0;
		node = vector <Node> (n << 10);
		root = vector <int> (n + 5), dist = vector <int> (n << 10);
		ch = vector <array <int, 2> > (n << 10);
	}
	
	int addNode (int tail, int val) {return node[++cnt] = (Node) {tail, val}, cnt;}
	
	int Get_rs (int x) {return dist[ch[x][1]] <= dist[ch[x][0]];}
		
	int Merge (int x, int y) {
		if (!x || !y) return x | y;
		if (node[x] < node[y]) swap (x, y);
		int p = ++cnt, rs = Get_rs (x);
		node[p].tail = node[x].tail, node[p].dis = node[x].dis;
		ch[p][rs ^ 1] = ch[x][rs ^ 1];
		ch[p][rs] = Merge (ch[x][rs], y);
		dist[p] = dist[ch[p][Get_rs (p)]] + 1;
		return p;
	}
	
} LT;

int n, m, k;

void init () {}

void AddNotTreeLink (int f, int u, vector <pair <int, int> > &pre, 
vector <int> &dis, vector <vector <array <int, 3> > > &G) {
	for (int i = 1; i <= n; ++i) if (dis[i] < INT_MAX) {
		for (auto &[v, w, id] : G[i]) if (dis[v] < INT_MAX && id != pre[i].first) {
			LT.root[i] = LT.Merge (LT.root[i], LT.addNode (v, dis[v] + w - dis[i]));
			//cout << i << " " << v << " " << dis[v] + w - dis[i] << endl;
		}
	}
}

void AddTreeLink (int f, int u, vector <int> &vis, vector <pair <int, int> > &pre, 
vector <int> &dis, vector <vector <array <int, 3> > > &revG) {
	vis[u] = true;
	if (pre[u].first) {
		//cout << u << " " << pre[u].second << endl;
		LT.root[u] = LT.Merge (LT.root[u], LT.root[pre[u].second]);
	}
	for (auto &[v, w, id] : revG[u]) if (!vis[v] && pre[v].first == id) {
		AddTreeLink (u, v, vis, pre, dis, revG);
	}
}

void charming () {
	init ();
	cin >> n >> m >> k;
	vector <vector <array <int, 3> > > G (n + 5), revG (n + 5);
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		G[u].emplace_back ((array <int, 3>) {v, w, i});
		revG[v].emplace_back ((array <int, 3>) {u, w, i});
	}
	auto [dis, pre] = Dijkstra (n, n, revG).Get_dis ();
	LT = LeftistTree (n);
	vector <int> vis (n + 5);
	AddNotTreeLink (0, n, pre, dis, G);
	AddTreeLink (0, n, vis, pre, dis, revG);
	priority_queue <Node> pq;
	if (k == 1) return void (cout << dis[1] << endl);
	else --k;
	if (LT.root[1]) pq.push ((Node) {LT.root[1], dis[1] + LT.node[LT.root[1]].dis});
	while (!pq.empty ()) {
		Node cur = pq.top ();
		pq.pop (), --k;
		if (!k) return void (cout << cur.dis << endl);
		if (LT.ch[cur.tail][0]) {
			pq.push ((Node) {LT.ch[cur.tail][0], cur.dis - LT.node[cur.tail].dis
			+ LT.node[LT.ch[cur.tail][0]].dis});
		}
		if (LT.ch[cur.tail][1]) {
			pq.push ((Node) {LT.ch[cur.tail][1], cur.dis - LT.node[cur.tail].dis
			+ LT.node[LT.ch[cur.tail][1]].dis});
		}
		int x = LT.root[LT.node[cur.tail].tail];
		if (x) pq.push ((Node) {x, cur.dis + LT.node[x].dis});
	}
	cout << -1 << endl;
}

signed main () {
	charming ();
	return 0;
}