#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Dijsktra {
	int n;
	vector <int> vis, dis;
	vector <vector <pair <int, int> > > G;
	
	Dijsktra (int n, vector <vector <pair <int, int> > > &G) {
		this -> n = n;
		vis = vector <int> (n << 2);
		dis = vector <int> (n << 2, LLONG_MAX);
		this -> G = G;
	}
	
	void Solve (int s) {
		priority_queue <pair <int, int>, vector <
		pair <int, int> >, greater <pair <int, int> > > pq;
		pq.push (make_pair (0, s));
		dis[s] = 0;
		while (!pq.empty ()) {
			int u = pq.top ().second;
			pq.pop ();
			if (vis[u]) continue;
			vis[u] = true;
			//cout << u << " " << dis[u] << endl;
			for (int i = 0, v, w; i < G[u].size (); ++i) {
				v = G[u][i].first, w = G[u][i].second;
				if (vis[v]) continue;
				else if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					pq.push (make_pair (dis[v], v));
				}
			}
		}
	}
};

int x, y, z, n;

void init () {}
#define emplace_back push_back
void charming () {
	cin >> x >> y >> z;
	string s;
	cin >> s, n = s.size (), s = '#' + s;
	//cout << n << endl;
	vector <vector <pair <int, int> > > G (n << 2);
	G[0].emplace_back (make_pair (n * 2 + 1, z));
	for (int i = 1; i <= n; ++i) {
		G[i - 1].emplace_back (make_pair (i, s[i] == 'a' ? x : y));
		G[i].emplace_back (make_pair (i + n, z));
		G[i + n].emplace_back (make_pair (i, z));
	}
	G[2 * n + 1].emplace_back (make_pair (1 + n, s[1] == 'a' ? y : x));
	for (int i = 2; i <= n; ++i) {
		G[i - 1 + n].emplace_back (make_pair (i + n, s[i] == 'a' ? y : x));
	}
	Dijsktra Dij (n, G);
	Dij.Solve (0);
	cout << min (Dij.dis[n], Dij.dis[n + n]) << endl;
}

signed main () {
	//freopen ("data.in", "r", stdin);
	charming ();
	return 0;
}
