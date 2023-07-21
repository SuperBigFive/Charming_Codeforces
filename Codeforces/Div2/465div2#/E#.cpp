#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;
const int M = 1e2 + 5;

int n, p, q, tot;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s, n = s.size ();
	cin >> p >> q;	
	vector <int> isLeaf (N), siz (N);
	vector <array <int, 2> > ch (N);
	vector <vector <int> > mx (N, vector <int> (M, -INT_MAX));
	vector <vector <int> > mn (N, vector <int> (M, INT_MAX));
	vector <int> stk;
	
	for (int i = 0, d, lid, rid; i < n; ++i) {
		if (s[i] == '(') {
			continue;
		}
		else if (s[i] == '?') {
			continue;
		}
		else if (s[i] == ')') {
			++tot;
			rid = stk.back ();
			stk.pop_back ();
			lid = stk.back ();
			stk.pop_back ();
			ch[tot][0] = lid, ch[tot][1] = rid;
			siz[tot] = siz[lid] + siz[rid] + 1;
			stk.emplace_back (tot);
		}
		else {
			++tot;
			isLeaf[tot] = true;
			d = s[i] - '0';
			mn[tot][0] = mx[tot][0] = d;
			stk.emplace_back (tot);
		}
	}
	
	auto DFS = [&] (auto && me, int cur) -> void {
		if (isLeaf[cur]) return;
		int &lid = ch[cur][0], &rid = ch[cur][1];
		me (me, lid), me (me, rid);
		
		if (p <= 100) {
			for (int i = 1; i <= min (siz[cur], p); ++i) {
				for (int j = max (0ll, i - 1 - siz[rid]); j <= min (i - 1, siz[lid]); ++j) {
					mx[cur][i] = max (mx[cur][i], mx[lid][j] + mx[rid][i - 1 - j]);
					mn[cur][i] = min (mn[cur][i], mn[lid][j] + mn[rid][i - 1 - j]);
				}
			}
			for (int i = 0; i <= min (siz[cur], p); ++i) {
				for (int j = max (0ll, i - siz[rid]); j <= min (i, siz[lid]); ++j) {
					mx[cur][i] = max (mx[cur][i], mx[lid][j] - mn[rid][i - j]);
					mn[cur][i] = min (mn[cur][i], mn[lid][j] - mx[rid][i - j]);
				}
			}
		}
		else {
			for (int i = 0; i <= min (siz[cur], q); ++i) {
				for (int j = max (0ll, i - siz[rid]); j <= min (i, siz[lid]); ++j) {
					mx[cur][i] = max (mx[cur][i], mx[lid][j] + mx[rid][i - j]);
					mn[cur][i] = min (mn[cur][i], mn[lid][j] + mn[rid][i - j]);
				}
			}
			for (int i = 1; i <= min (siz[cur], q); ++i) {
				for (int j = max (0ll, i - 1 - siz[rid]); j <= min (i - 1, siz[lid]); ++j) {
					mx[cur][i] = max (mx[cur][i], mx[lid][j] - mn[rid][i - 1 - j]);
					mn[cur][i] = min (mn[cur][i], mn[lid][j] - mx[rid][i - 1 - j]);
				}
			}
		}
	};
	
	int rt = stk[0];
	DFS (DFS, rt);
	if (p <= 100) cout << mx[rt][p] << endl;
	else cout << mx[rt][q] << endl;
}

signed main () {
	charming ();
	return 0;
}