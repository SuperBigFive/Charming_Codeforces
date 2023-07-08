#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, mx;

void init () {}

void charming () {
	init ();
	cin >> n;	
	vector <vector <int> > adj (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	
	auto Get_rt1 = [&] (auto && me, int &rt, int &mx, int f, int u, int d) -> void {
		if (mx < d) mx = d, rt = u;
		for (auto &v : adj[u]) {
			if (v == f) continue;
			me (me, rt, mx, u, v, d + 1);
		}
	};
	
	auto Get_rt2 = [&] (auto && me, int e, int f, int u, int d, 
	vector <int> &city) -> void {
		city.emplace_back (u);
		if (u == e) {
			if (d & 1) cout << city[d / 2] << endl;
			else cout << min (city[d / 2 - 1], city[d / 2]) << " "
			<< max (city[d / 2 - 1], city[d / 2]) << endl;
			exit (0);
		}
		for (auto &v : adj[u]) {
			if (v == f) continue;
			me (me, e, u, v, d + 1, city);
		}
		city.pop_back ();
	};
	
	int rt1, rt2;
	Get_rt1 (Get_rt1, rt1 = -1, mx = -1, -1, 0, 1);
	Get_rt1 (Get_rt1, rt2 = -1, mx = -1, -1, rt1, 1);
	vector <int> city;
	Get_rt2 (Get_rt2, rt2, -1, rt1, 1, city);
}

signed main () {
	charming ();
	return 0;
}