#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, t, m, ans;

void init () {ans = 0;}

void DFS1 (int id, int lim, int last,
vector <int> &cur, vector <vector <int> > &First) {
	if (id > lim) {
		First.emplace_back (cur);
		return;
	}
	for (int i = last + 1; i <= n; ++i) {
		cur.emplace_back (i);
		DFS1 (id + 1, lim, i, cur, First);
		cur.pop_back ();
	}
}

void DFS2 (int id, int lim, vector <vector <int> > &team,
vector <int> &remain, set <pair <int, int> > &ban) {
	if (id >= lim) {
		for (int i = 0, siz; i < t; ++i) {
			siz = team[i].size ();
			for (int j = 0; j < siz; ++j) {
				for (int k = j + 1; k < siz; ++k) {
					if (ban.count (make_pair (team[i][j], team[i][k]))) return;
				}
			}
		}
		++ans;
		return;
	}
	for (int i = 0; i < t; ++i) {
		if (team[i].back () > remain[id]) continue;
		team[i].emplace_back (remain[id]);
		DFS2 (id + 1, lim, team, remain, ban);
		team[i].pop_back ();
	}
}

void charming () {
	init ();
	cin >> n >> t >> m;
	set <pair <int, int> > ban;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		if (a > b) swap (a, b);
		ban.insert (make_pair (a, b));
	}
	vector <int> cur;
	vector <vector <int> > First;
	DFS1 (1, t, 0, cur, First);
	for (auto v : First) {
		vector <vector <int> > team (t);
		vector <int> remain;
		for (int i = 0; i < t; ++i) team[i].emplace_back (v[i]);
		for (int i = 1, p = 0; i <= n; ++i) {
			while (p < t && v[p] < i) ++p;
			if (p < t && v[p] == i) continue;
			else remain.emplace_back (i);
		}
		DFS2 (0, n - t, team, remain, ban);
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}