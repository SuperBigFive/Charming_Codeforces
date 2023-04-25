#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1), b (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[a[i]] = i;
	}
	vector <int> pre (n + 1);
	for (int i = 1; i <= n; ++i) pre[i] = i;
	auto find = [&] (auto && me, int x) {
		if (x == pre[x]) return x;
		return pre[x] = me (me, pre[x]);
	};
	vector <pair <int, int> > edge;
	for (int i = 1; i <= n; ++i) {
		edge.emplace_back (make_pair (a[i], a[a[i]]));
		int fu = find (find, a[i]), fv = find (find, a[a[i]]);
		if (fu != fv) pre[fu] = fv;
	}
	int res = n;
	for (int i = 1; i <= n; ++i) if (i == pre[i]) --res;
	for (int i = 1; i < n; ++i) {
		if (find (find, i) == find (find, i + 1)) {
			cout << res - 1 << endl;
			return;
		}
	}
	cout << res + 1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}