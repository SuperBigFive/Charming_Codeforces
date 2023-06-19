#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;	
	vector <int> p (n + 5), a (n + 5);
	vector <vector <int> > G (n + 5);
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		G[p[i]].emplace_back (i);
	}
	for (int i = 1; i <= n; ++i) cin >> a[i];
	set <int> s;
	vector <int> negNum (n + 5);
	vector <int> needOne (n + 5);
	
	auto DFS1 = [&] (auto && me, int u) -> void {
		negNum[u] = (a[u] == -1);
		for (int v : G[u]) me (me, v), negNum[u] += negNum[v];
	};
	
	auto DFS2 = [&] (auto && me, int u) -> bool {
		if (a[u] != -1 && a[u] < k) s.insert (a[u]);
		else if (a[u] == k) return false;
		for (int v : G[u]) if (!me (me, v)) return false;
		return true;
	};
	
	DFS1 (DFS1, 1);
	for (int i = 1; i <= n; ++i) {
		s.clear ();
		if (!DFS2 (DFS2, i)) continue;
		else if (s.size () >= k - 1) needOne[i] = true;
		if (s.size () == k && negNum[i] <= 1) return void (cout << "Alice" << endl);
	}
	
	for (int i = 1, j; i <= n; ++i) {
		if (a[i] > -1) continue;
		else {
			j = i;
			while (j) {
				if (needOne[j] && negNum[j] == 1) return void (cout << "Alice" << endl);
				else j = p[j];
			}
		}
	}
	cout << "Bob" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}