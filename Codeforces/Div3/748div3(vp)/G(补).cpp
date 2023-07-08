#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, q;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s, n = s.length (), s = '#' + s;
	int blo = sqrt (n) + 1, m = (n - 1) / blo + 1;
	vector <int> bl (n + 5), stk;
	vector <pair <int, int> > st_len (m + 5);
	for (int i = 1; i <= n + 1; ++i) {
		bl[i] = (i - 1) / blo + 1;
		if (bl[i] != bl[i - 1] || i == n + 1) {
			stk.emplace_back (-1);
			st_len[bl[i - 1]] = make_pair (stk[0], stk.size () - 1);
			stk.clear ();
		}
		if (s[i] == '(' || s[i] == ')') {
			if (stk.size () && stk.back () == 1) stk.pop_back ();
			else stk.emplace_back (1);
		}
		else {
			if (stk.size () && stk.back () == 0) stk.pop_back ();
			else stk.emplace_back (0);
		}
	}
	vector <vector <pair <int, int> > > sum (m + 5);
	vector <vector <pair <int, int> > > from_l (m + 5), from_r (m + 5);
	for (int i = 0; i < m + 5; ++i) {
		sum[i].resize (m + 5, make_pair (-1, 0));
		from_l[i].resize (blo + 5, make_pair (-1, 0));
		from_r[i].resize (blo + 5, make_pair (-1, 0));
	}
	auto merge = [&] (pair <int, int> &st_len1, pair <int,
	int> &st_len2) -> pair <int, int> {
		int cur_st = st_len1.first, cur_len = st_len1.second;
		if (cur_st == -1) return st_len2;
		else if (st_len2.first == -1) return st_len1;
		else if (cur_st ^ (cur_len & 1) == st_len2.first) {
			cur_len += st_len2.second;
		}
		else {
			if (cur_len == st_len2.second) {
				cur_st = -1;
				cur_len = 0;
			}
			else if (cur_len > st_len2.second) {
				cur_len -= st_len2.second;
			}
			else {
				cur_st ^= 1;
				cur_len = st_len2.second - cur_len;
			}
		}
		return make_pair (cur_st, cur_len);
	};
	for (int i = 1; i <= m; ++i) {
		pair <int, int> res = make_pair (-1, 0);
		for (int j = i; j <= m; ++j) {
			res = merge (res, st_len[j]);
			sum[i][j] = res;
		}
		if (i < m) {
			vector <int> stk_l;
			for (int j = 1; j <= blo; ++j) {
				int be = i * blo + 1;
				if (s[be - j] == '(' || s[be - j] == ')') {
					if (stk_l.size () && stk_l.back () == 1) stk_l.pop_back ();
					else stk_l.emplace_back (1);
				}
				else {
					if (stk_l.size () && stk_l.back () == 0) stk_l.pop_back ();
					else stk_l.emplace_back (0);
				}
				if (stk_l.size () <= 0) from_l[i][j] = make_pair (-1, 0);
				else from_l[i][j] = make_pair (stk_l.back (), stk_l.size ());
			}
		}
		if (i > 1) {
			vector <int> stk_r;
			for (int j = 1; j <= blo; ++j) {
				int be = (i - 1) * blo;
				if (s[be + j] == '(' || s[be + j] == ')') {
					if (stk_r.size () && stk_r.back () == 1) stk_r.pop_back ();
					else stk_r.emplace_back (1);
				}
				else {
					if (stk_r.size () && stk_r.back () == 0) stk_r.pop_back ();
					else stk_r.emplace_back (0);
				}
				if (stk_r.size () <= 0) from_r[i][j] = make_pair (-1, 0);
				else from_r[i][j] = make_pair (stk_r[0], stk_r.size ());
			}
		}
	}
	cin >> q;
	for (int i = 1, l, r; i <= q; ++i) {
		cin >> l >> r;
		if (bl[l] == bl[r]) {
			stk.clear ();
			for (int i = l; i <= r; ++i) {
				if (s[i] == '(' || s[i] == ')') {
					if (stk.size () && stk.back () == 1) stk.pop_back ();
					else stk.emplace_back (1);
				}
				else {
					if (stk.size () && stk.back () == 0) stk.pop_back ();
					else stk.emplace_back (0);
				}
			}
			cout << ceil (stk.size () / 2) << endl;
		}
		else {
			int bl_l = bl[l], bl_r = bl[r];
			int dis_l = bl_l * blo + 1 - l;
			int dis_r = r - (bl_r - 1) * blo;
			pair <int, int> res;
			if (bl_l < bl_r - 1) {
				res = merge (from_l[bl_l][dis_l], sum[bl_l + 1][bl_r - 1]);
				res = merge (res, from_r[bl_r][dis_r]);
			}
			else res = merge (from_l[bl_l][dis_l], from_r[bl_r][dis_r]);
			cout << ceil (res.second / 2) << endl;
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}