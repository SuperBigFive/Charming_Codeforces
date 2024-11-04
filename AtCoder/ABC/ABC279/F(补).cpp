#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;
const int M = 2e6 + 5;

int n, q, tot;
int pre[M];
map <int, int> id, siz, cnt;
void init () {tot += N << 1;}

int find (int x) {
	if (x == pre[x]) return x;
	return pre[x] = find (pre[x]);
}

void charming () {
	init ();
	cin >> n >> q;
	vector <vector <int> > p (M);
	for (int i = 1; i <= n; ++i) {
		pre[i] = tot;
		pre[tot] = tot;
		p[i].emplace_back (tot);
		id[tot] = i;
		++tot;
	}
	for (int i = 1, opt, x, y; i <= q; ++i) {
		cin >> opt >> x;
		if (opt == 1) {
			cin >> y;
			int fx = find (p[x].back ()), fy = find (p[y].back ());
			pre[fy] = fx;
			p[id[fy]].emplace_back (tot);
			id[tot] = id[fy];
			pre[tot] = tot;
			++tot;
		}
		else if (opt == 2) {
			pre[++n] = p[x].back ();
		}
		else {
			int root = find (x);
			cout << id[root] << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}