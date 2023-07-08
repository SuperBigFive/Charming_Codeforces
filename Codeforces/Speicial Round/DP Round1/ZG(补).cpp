#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 55;

struct Node {
	int id, last_w, isOdd, sum_w;
	bool operator < (const Node &x) const {
		return this -> sum_w > x.sum_w;
	}
};
int n, m;

void init () {}

void dijkstra (vector <vector <pair <int, int> > > &adj,
vector <vector <vector <int> > > &dis) {
	priority_queue <Node> pq;
	pq.push ({1, 0, 0, 0});
	dis[1][0][0] = 0;
	Node cur;
	while (!pq.empty ()) {
		cur = pq.top (), pq.pop ();
		for (auto &[v, w] : adj[cur.id]) {
			int cost = 0;
			if (cur.isOdd) {
				cost = (cur.last_w + w) * (cur.last_w + w);
			}
			if (dis[v][w][cur.isOdd ^ 1] > cur.sum_w + cost) {
				dis[v][w][cur.isOdd ^ 1] = cur.sum_w + cost;
				pq.push ({v, w, cur.isOdd ^ 1, dis[v][w][cur.isOdd ^ 1]});
			}
		}
	}
}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <pair <int, int> > > adj (n + 1);
	vector <vector <vector <int> > > dis (n + 1,
	vector <vector <int> > (M, vector <int> (2, INT_MAX)));
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back (make_pair (v, w));
		adj[v].emplace_back (make_pair (u, w));
	}
	dijkstra (adj, dis);
	for (int i = 1, res; i <= n; ++i) {
		res = INT_MAX;
		for (int j = 0; j < M; ++j)
		res = min (res, dis[i][j][0]);
		cout << (res < INT_MAX ? res : -1) << " \n"[i == n];
	}
}

signed main () {
	charming ();
	return 0;
}