#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> a (n + 5), be;
	vector <vector <int> > adj (n + 5);
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!a[i]) be.emplace_back (i);
		mx = max (a[i], mx);
	}
	
	vector <int> pre (n + 5);
	for (int i = 1; i <= n; ++i) pre[i] = i;
	
	auto find = [&] (auto && me, int x) -> int {
		if (x == pre[x]) return x;
		return pre[x] = me (me, pre[x]);
	};
	
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
		int fu = find (find, u), fv = find (find, v);
		if (fu == fv) continue;
		else pre[fu] = fv;
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == pre[i]) ++cnt;
	}
	if (cnt > 1) {cout << "No" << endl; return;}
	
	vector <int> bel (n + 5), siz (n + 5);
	vector <vector <int> > remain (n + 5);
	for (int i = 1; i <= n; ++i) pre[i] = i;
	
	for (int i = 0, u, power; i < be.size (); ++i) {
		priority_queue <pair <int, int> , vector <pair <int, int> >,
		greater <pair <int, int> > > pq;
		if (bel[be[i]]) continue;
		u = be[i], power = 1, bel[u] = i + 1, siz[i + 1] = 1;
		
		for (auto v : adj[u]) {
			pq.push (make_pair (a[v], v));
		}
		
		while (!pq.empty ()) {
			auto [val, v] = pq.top ();
			if (power < val) break;
			pq.pop ();
			if (find (find, bel[v]) == i + 1) continue;
			if (!bel[v]) {
				power += 1, siz[i + 1] += 1, bel[v] = i + 1;
				
				for (auto it : adj[v]) {
					pq.push (make_pair (a[it], it));
				}
			}
			else {
				int fv = find (find, bel[v]);
				pre[fv] = i + 1;
				power += siz[fv];
				siz[i + 1] += siz[fv];
				for (auto it : remain[fv]) {
					pq.push (make_pair (a[it], it));
				}
			}
		}
		while (!pq.empty ()) {
			auto [val, v] = pq.top ();
			pq.pop ();
			if (find (find, bel[v]) != i + 1)
			remain[i + 1].emplace_back (v);
		}
		if (power >= mx) {cout << "Yes" << endl; return;}
	}
	cout << "No" << endl;
}


signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}