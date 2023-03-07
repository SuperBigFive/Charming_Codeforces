#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

struct Node {
	int sum;
	int tot;
}node[maxn];
int n;
int k[maxn];
vector <int> m[maxn];
set <pair <double, int> > c, res_c;

void init () {}

bool cmp (Node &a, Node &b) {
	return a.sum > b.sum;
}

double get_res (int t) {
	double val, res = 0;
	for (int i = 1; i < maxn; ++i) {
		val = 0;
		for (auto it : m[i]) {
			if (it >= t) val += 1;
			else val += (double) it / t;
		}
		if (c.size () < t) c.insert (make_pair (val, i)), res += val;
		else {
			auto [mn, id] = *c.begin ();
			if (mn < val) {
				c.erase (make_pair (mn, id));
				c.insert (make_pair (val, i));
				res -= mn;
				res += val;
			}
		}
	}
	return res;
}

void charming () {
	init ();
	cin >> n;
	int mx = -1;
	for (int i = 1; i < maxn; ++i)
	node[i].tot = i;
	for (int i = 1, id; i <= n; ++i) {
		cin >> id >> k[i];
		m[id].emplace_back (k[i]);
		node[id].sum += k[i];
		mx = max (mx, k[i]);
	}
	int res_t;
	double res_n = -1;
	for (int i = 1; i <= mx; ++i) {
		c.clear ();
		double cur = get_res (i);
		if (res_n < cur) {
			res_t = i;
			res_n = cur;
			res_c = c;
		}
	}
	sort (node + 1, node + maxn, cmp);
	int cur = 0;
	c.clear ();
	for (int i = 1; i < maxn; ++i) {
		c.insert (make_pair (node[i].sum, node[i].tot));
		if (i <= mx) cur += node[i].sum;
		else if ((double) (cur / i) > res_n) {
			res_t = i;
			res_n = (double) cur / i;
			res_c = c;
		}
	}
	cout << res_t << endl;
	for (auto it : res_c) {
		cout << it.second << " ";
	}
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}