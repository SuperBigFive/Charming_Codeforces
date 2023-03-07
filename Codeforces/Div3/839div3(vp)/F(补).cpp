#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m, k;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init () {}

void charming () {
	init ();
	cin >> n >> m >> k;
	vector <array <array <int, 35>, 35> > mp (k + 1);
	for (int i = 0; i <= k; ++i) {
		string s;
		for (int j = 0; j < n; ++j) {
			cin >> s;
			for (int p = 0; p < m; ++p) {
				if (s[p] == '0') mp[i][j + 1][p + 1] = 0;
				else mp[i][j + 1][p + 1] = 1;
			}
		}
	}
	for (int i = 0; i <= k; ++i) {
		vector <vector <int> > st (n + 1);
		for (int j = 0; j < n + 1; ++j)
		st[j].resize (m + 1);
		for (int j = 2; j < n; ++j) {
			for (int p = 2; p < m; ++p) {
				bool ok = true;
				for (int q = 0; q < 4; ++q) {
					int nx = j + dx[q], ny = p + dy[q];
					if (mp[i][nx][ny] == mp[i][j][p]) {
						ok = false;
						break;
					}
				}
				st[j][p] = ok;
			}
		}
		bool flag = true;
		vector <set <pair <int, int> > > change (k + 1);
		set <pair <int, int> > chk;
		set <int> cho;
		for (int j = 0; j <= k; ++j) {
			if (j == i) continue;
			cho.insert (j);
		}
		for (int j = 0; j <= k && flag; ++j) {
			if (j == i) continue;
			for (int p = 1; p <= n && flag; ++p) {
				for (int q = 1; q <= m; ++q) {
					if (mp[j][p][q] != mp[i][p][q]) {
						if (!st[p][q]) {
							flag = false;
							break;
						}
						change[j].insert (make_pair (p, q));
						chk.insert (make_pair (p, q));
					}
				}
			}
			for (auto [x1, y1] : chk) {
				for (auto [x2, y2] : chk) {
					if (x1 == x2 && y1 == y2) continue;
					for (int p = 0; p < 4; ++p) {
						if (x1 + dx[p] == x2 && y1 + dy[p] == y2) {
							flag = false;
							break;
						}
					}
				}
			}
		}
		if (!flag) continue;
		vector <vector <int> > adj (k + 1);
		for (int j = 0; j <= k && flag; ++j) {
			if (j == i) continue;
			for (int p = j + 1; p <= k; ++p) {
				if (p == i) continue;
				bool flag1 = false, flag2 = false, flag3 = false;
				for (auto [x, y] : change[j]) {
					if (change[p].count (make_pair (x, y)))
					flag1 = true;
					else flag2 = true;
				}
				if (flag1 && flag2) {
					for (auto [x, y] : change[p]) {
						if (!change[j].count (make_pair (x, y))) {
							flag3 = true;
							break;
						}
					}
				}
				if (flag3) {
					flag = false;
					break;
				}
				else if (flag1) {
					if (change[j].size () >= change[p].size ()) {
						adj[j].emplace_back (p);
						if (cho.count (p)) cho.erase (p);
					}
					else {
						adj[p].emplace_back (j);
						if (cho.count (j)) cho.erase (j);
					}
				}
			}
		}
		if (!flag) continue;
		cout << i + 1 << endl;
		vector <pair <int, pair <int, int> > > opt;
		set <pair <int, int> > vis1;
		set <int> vis2;
		auto dfs = [&] (auto&& me, int u) -> void {
			vis2.insert (u);
			for (auto v : adj[u]) {
				if (vis2.count (v)) continue;
				me (me, v);
			}
			for (auto [x, y] : change[u]) {
				if (vis1.count (make_pair (x, y))) continue;
				vis1.insert (make_pair (x, y));
				opt.emplace_back (make_pair (1, make_pair (x, y)));	
			}
			opt.emplace_back (make_pair (2, make_pair (u + 1, u + 1)));
		};
		for (auto it : cho) {
			if (it == i || vis2.count (it));
			dfs (dfs, it);
		}
		cout << opt.size () << endl;
		for (auto [type, it] : opt) {
			cout << type << " ";
			if (type == 1) cout << it.first << " " << it.second << endl;
			else cout << it.first << endl;
		}
		break;
	}
}

signed main () {
	charming ();
	return 0;
}