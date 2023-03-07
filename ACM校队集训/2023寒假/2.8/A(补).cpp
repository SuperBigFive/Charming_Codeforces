#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

struct Node {
	int sum = 0, num = 0, id = 0;
	bool operator >= (const Node &a) const {
		return this -> sum * a.num >= a.sum * this -> num;
	}
	Node operator + (const Node &a) const {
		Node tmp;
		tmp.sum = this -> sum + a.sum;
		tmp.num = this -> num + a.num;
		tmp.id = max (this -> id, a.id);
		return tmp;
	}
};

void init () {}

void charming (int case_cnt) {
	init ();
	cin >> n >> m;
	vector <int> a (n + 5), b (m + 5);
	vector <Node> na (n + 5), nb (m + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		na[i].sum = a[i], na[i].num = 1, na[i].id = i;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		nb[i].sum = b[i], nb[i].num = 1, nb[i].id = i;
	}
	auto merge = [&] (vector <Node> &node, int siz) -> vector <Node> {
		vector <Node> res;
		for (int i = 1; i <= siz; ++i) {
			while (res.size () && node[i] >= res.back ()) {
				node[i] = node[i] + res.back ();
				res.pop_back ();
			}
			res.emplace_back (node[i]);
		}
		return res;
	};
	vector <Node> nna = merge (na, n), nnb = merge (nb, m);
	int p = 0, q = 0, k = 0;
	ll res = 0;
	n = nna.size (), m = nnb.size ();
	while (p < n || q < m) {
		if (q >= m || (p < n && nna[p] >= nnb[q])) {
			for (int i = nna[p].id - nna[p].num + 1; i <= nna[p].id; ++i)
			res += a[i] * (++k);
			++p;
		} else {
			for (int i = nnb[q].id - nnb[q].num + 1; i <= nnb[q].id; ++i)
			res += b[i] * (++k);
			++q;
		}
	}
	cout << "Case " << case_cnt << ": " << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}