#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int h, w, rs, cs, n, q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
vector <pair <int, int> > wall;
vector <int> wall_row[maxn], wall_col[maxn];
map <char, int> str2num;
map <int, int> bel_row, bel_col;

void init () {
	str2num['L'] = 0;
	str2num['R'] = 1;
	str2num['U'] = 2;
	str2num['D'] = 3;
}

bool cmp1 (pair <int, int> &a, pair <int, int> &b) {
	return a.first < b.first;
}

bool cmp2 (pair <int, int> &a, pair <int, int> &b) {
	return a.second < b.second;
}

void charming () {
	init ();
	cin >> h >> w >> rs >> cs;
	cin >> n;
	for (int i = 1, r, c; i <= n; ++i) {
		cin >> r >> c;
		wall.emplace_back (make_pair (r, c));
	}
	sort (wall.begin (), wall.end (), cmp1);
	int last = -1, cnt1 = 0;
	for (auto it : wall) {
		auto [r, c] = it;
		if (r != last) bel_row[r] = ++cnt1, last = r;
		wall_row[bel_row[r]].emplace_back (c);
	}
	sort (wall.begin (), wall.end (), cmp2);
	last = -1;
	int cnt2 = 0;
	for (auto it : wall) {
		auto [r, c] = it;
		if (c != last) bel_col[c] = ++cnt2, last = c;
		wall_col[bel_col[c]].emplace_back (r);
	}
	for (int i = 1; i <= cnt1; ++i)
	sort (wall_row[i].begin (), wall_row[i].end ());
	for (int i = 1; i <= cnt2; ++i)
	sort (wall_col[i].begin (), wall_col[i].end ());
	cin >> q;
	char d;
	for (int i = 1, l, dir, id; i <= q; ++i) {
		cin >> d;
		cin >> l;
		dir = str2num[d];
		if (dir < 2) {
			if (dir == 0) {
				if (!bel_row.count (rs)) {
					cs = max (1ll, cs - l);
				}
				else {
					id = lower_bound (wall_row[bel_row[rs]].begin (),
					wall_row[bel_row[rs]].end (), cs) - wall_row[bel_row[rs]].begin () - 1;
					if (id <= -1) cs = max (1ll, cs - l);
					else cs = max (wall_row[bel_row[rs]][id] + 1, cs - l);
				}
			}
			else if (dir == 1) {
				if (!bel_row.count (rs)) {
					cs = min (w, cs + l);
				}
				else {
					id = lower_bound (wall_row[bel_row[rs]].begin (),
					wall_row[bel_row[rs]].end (), cs) - wall_row[bel_row[rs]].begin ();
					if (id >= wall_row[bel_row[rs]].size ()) cs = min (w, cs + l);
					else cs = min (wall_row[bel_row[rs]][id] - 1, cs + l);
				}
			}
		}
		else {
			if (dir == 2) {
				if (!bel_col.count (cs)) {
					rs = max (1ll, rs - l);
				}
				else {
						id = lower_bound (wall_col[bel_col[cs]].begin (),
						wall_col[bel_col[cs]].end (), rs) - wall_col[bel_col[cs]].begin () - 1;
						if (id <= -1) rs = max (1ll, rs - l);
						else rs = max (wall_col[bel_col[cs]][id] + 1, rs - l);
				}
			}
			else if (dir == 3) {
				if (!bel_col.count (cs)) {
					rs = min (h, rs + l);
				}
				else {
					id = lower_bound (wall_col[bel_col[cs]].begin (),
					wall_col[bel_col[cs]].end (), rs) - wall_col[bel_col[cs]].begin ();
					if (id >= wall_col[bel_col[cs]].size ()) rs = min (h, rs + l);
					else rs = min (wall_col[bel_col[cs]][id] - 1, rs + l);
				}
			}
		}
		cout << rs << " " << cs << endl;
	}
}

signed main () {
	charming ();
	return 0;
}