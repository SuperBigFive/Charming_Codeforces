#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;
mt19937 rnd (random_device {}());

int t, l, r;

void init () {}

vector <int> to_digit (ll num) {
	vector <int> res;
	while (num) res.emplace_back (num % 10), num /= 10;
	reverse (res.begin (), res.end ());
	return res;
}

int to_num (vector <int> d) {
	ll res = 0, siz = d.size ();
	for (int i = 0; i < siz; ++i)
	res = res * 10 + d[i];
	return res;
}

int force (int l, int r) {
	int res = l, cur = 10;
	for (int i = l, mx, mn, j; i <= r; ++i) {
		mx = -1, mn = 10, j = i;
		while (j) {
			mx = max (mx, j % 10);
			mn = min (mn, j % 10);
			j /= 10;
		}
		if (mx - mn < cur) cur = mx - mn, res = i;
	}
	return res;
}

void charming () {
	init ();
	cin >> l >> r;
	if (l > r) swap (l, r);
	int res = l, cur = 10;
	vector <int> dl = to_digit (l), dr = to_digit (r);
	if (dl.size () != dr.size ()) {
		for (int i = 0; i < dl.size (); ++i)
		cout << "9";
		cout << endl;
		return;
	}
	int p = 0, siz = dl.size (), mx = -1, mn = 10;
	while (p < siz && dl[p] == dr[p]) {
		mx = max (mx, dl[p]), mn = min (mn, dl[p]), ++p;
	}
	if (p == siz) {
		cout << l << endl;
		return;
	}
	else if (p == siz - 1) {
		cout << force (l, r) << endl;
		return;
	}
	else {
		vector <int> d = dl;
		
		for (int i = dl[p] + 1; i <= dr[p] - 1; ++i) {
			d[p] = i;
			int nmx = max (mx, i), nmn = min (mn, i);
			if (nmx - nmn < cur) {
				cur = nmx - nmn;
				for (int j = p + 1; j < siz; ++j) d[j] = i;
				res = to_num (d);
			}
		}
		
		d[p] = dl[p] + 1;
		for (int i = p + 1; i < siz; ++i) d[i] = 0;
		if (max (mx, d[p]) < cur) {
			cur = max (mx, d[p]);
			res = to_num (d);
		}
		d[p] = dr[p];
		if (max (mx, d[p]) < cur) {
			cur = max (mx, d[p]);
			res = to_num (d);
		}
		
		int nmx = max (mx, dl[p]), nmn = min (mn, dl[p]);
		d = dl;
		for (int i = p + 1; i < siz; ++i) {
			if (dl[i] != 9) {
				d[i] = max (nmn, d[i] + 1);
				int nnmx = max (nmx, d[i]);
				int nnmn = min (nmn, d[i]);
				if (nnmx - nnmn < cur) {
					cur = nnmx - nnmn;
					for (int j = i + 1; j < siz; ++j) d[j] = d[i];
					res = to_num (d);
				}
			}
			d = dl;
			nmx = max (nmx, dl[i]);
			nmn = min (nmn, dl[i]);
		}
		if (nmx - nmn < cur) cur = nmx - nmn, res = l;
		
		d = dr;
		nmx = max (mx, dr[p]), nmn = min (mn, dr[p]);
		if (nmx < cur) {
			cur = nmx;
			vector <int> nd = dl;
			nd[p] = dr[p];
			for (int i = p + 1; i < siz; ++i) nd[i] = 0;
			res = to_num (nd);
		}
		for (int i = p + 1; i < siz; ++i) {
			if (dr[i] != 0) {
				d[i] = min (dr[i] - 1, nmx);
				int nnmx = max (nmx, d[i]);
				int nnmn = min (nmn, d[i]);
				if (nnmx - nnmn < cur) {
					cur = nnmx - nnmn;
					for (int j = i + 1; j < siz; ++j) d[j] = d[i];
					res = to_num (d);
				}
			}
			d = dr;
			nmx = max (nmx, dr[i]);
			nmn = min (nmn, dr[i]);
		}
		if (nmx - nmn < cur) cur = nmx - nmn, res = r;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) 
	charming ();
	return 0;
}