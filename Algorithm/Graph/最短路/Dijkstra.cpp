#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

struct Dijsktra {
	int n, s;
	vector <int> dis, vis;
	vector <vector <pair <int, int> > > G;
	
	void Solve () {
		priority_queue <pair <int, int>, vector <pair <int, int> >,
		greater <pair <int, int> > > pq;
		pq.push (make_pair (0, s)), dis[s] = 0;
		while (!pq.empty ()) {
			auto [udis, u] = pq.top ();
			pq.pop ();
			vis[u] = 1;
			for (auto [v, w] : G[u]) {
				if (vis[v]) continue;
				else if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					pq.push (make_pair (dis[v], v));
				}
			}
		}
	}
	
	Dijsktra (int n, int s, vector <vector <pair <int, int> > > &G) {
		this -> n = n, this -> s = s, this -> G = G;
		dis = vector <int> (n + 5, INT_MAX);
		vis = vector <int> (n + 5, 0);
		Solve ();
	}
};

void charming () {
	init ();
	cin >> n;	
	vector <array <int, 3> > pos (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> pos[i][0] >> pos[i][1];
		pos[i][2] = i;
	}
	vector <vector <pair <int, int> > > G (n + 5);
	for (int d = 0; d <= 1; ++d) {
		sort (pos.begin () + 1, pos.begin () + 1 + n, [&] (array <int, 3> &x,
		array <int, 3> &y) {return x[d] < y[d];});
		for (int i = 1, u, v; i <= n; ++i) {
			u = pos[i][2];
			if (i > 1) {
				v = pos[i - 1][2];
				G[u].emplace_back (make_pair (v, pos[i][d] - pos[i - 1][d]));
			}
			if (i < n) {
				v = pos[i + 1][2];
				G[u].emplace_back (make_pair (v, pos[i + 1][d] - pos[i][d]));
			}
		}
	}
	cout << Dijsktra (n, 1, G).dis[n] << endl;
}

signed main () {
	charming ();
	return 0;
}
