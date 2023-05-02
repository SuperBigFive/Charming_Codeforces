#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int ull
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

const ull mask = std::chrono::steady_clock::now ().time_since_epoch ().count ();

ull shift (ull x) {
  x ^= mask;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  x ^= mask;
  return x;
}

void init () {}

bool FindCircle (int f, int u, vector <int> &vis, vector <int> &stk, 
vector <int> &inCircle, vector <vector <int> > &G) {
	stk.emplace_back (u);
	vis[u] = 1;
	for (auto &v : G[u]) {
		if (v == f) continue;
		else if (vis[v]) {
			vector <int> nstk;
			while (stk.size () && stk.back () != v) {
				inCircle[stk.back ()] = 1;
				nstk.emplace_back (stk.back ());
				stk.pop_back ();
			}
			inCircle[v] = 1, nstk.emplace_back (v);
			stk = nstk;
			return true;
		}
		else if (FindCircle (u, v, vis, stk, inCircle, G)) return true;
	}
	stk.pop_back ();
	return false;
}

int HashTree (int f, int u, vector <vector <int> > &G) {
	int hash_val = 1;
	for (auto &v : G[u]) {
		if (v == f) continue;
		hash_val += shift (HashTree (u, v, G));
	}
	return hash_val;
}

bool Check (vector <int> val) {
	bool isSame = true;
	for (auto &it : val) isSame &= (it == val[0]);
	if (isSame) return true;
	else if ((int) val.size () & 1) return false;
	else {
		for (int i = 0; i < val.size (); i += 2) {
			if (val[i] != val[0] || val[i + 1] != val[1]) return false;
		}
		return true;
	}
}

void charming () {
	init ();
	cin >> n >> m;
	vector <pair <int, int> > edge;
	vector <vector <int> > G (n + 5);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
		edge.emplace_back (make_pair (u, v));
	}
	if (m == n - 1) return void (cout << "YES" << endl);
	else if (m > n) return void (cout << "NO" << endl);
	else {
		vector <int> vis (n + 5), inCircle (n + 5), stk;
		FindCircle (0, 1, vis, stk, inCircle, G);
		G = vector <vector <int> > (n + 5);
		for (int i = 0, u, v; i < m; ++i) {
			u = edge[i].first, v = edge[i].second;
			if (!inCircle[u] || !inCircle[v]) {
				G[u].emplace_back (v);
				G[v].emplace_back (u);
			}
		}
		vector <int> hash_val;
		for (auto &v : stk) hash_val.emplace_back (HashTree (0, v, G));
		if (Check (hash_val)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}