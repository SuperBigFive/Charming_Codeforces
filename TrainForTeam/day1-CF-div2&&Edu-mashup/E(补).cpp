#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int q, siz, tot;
int pre[maxn], bel[maxn];
vector <int> root[maxn];

int find (int x) {
	if (x == pre[x]) return x;
	return pre[x] = find (pre[x]);
}

void add_root (int x) {
	root[x].emplace_back (++tot);
	bel[tot] = x;
	pre[tot] = tot;
}

void init () {
	tot = 5e5 + 5;
	for (int i = 1; i < 5e5 + 5; ++i)
	add_root (i);
}

void charming () {
	init ();
	cin >> q;
	int opt, x, y;
	for (int i = 1; i <= q; ++i) {
		cin >> opt >> x;
		if (opt == 1) {
			pre[++siz] = root[x].back ();
		}
		else {
			cin >> y;
			if (x == y) continue;
			pre[root[x].back ()] = root[y].back ();
			add_root (x);
		}
	}
	for (int i = 1; i <= siz; ++i) {
		cout << bel[find (i)] << " ";
	}
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}