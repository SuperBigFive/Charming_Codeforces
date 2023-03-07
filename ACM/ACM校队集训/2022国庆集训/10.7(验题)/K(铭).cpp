#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;
int a[maxn], p[maxn];
vector <int> cut;
map <int, int> lim, cnt;

void init () {
	cut.clear ();
	lim.clear ();
	cnt.clear ();
}

void charming () {
	init ();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1, x, y; i <= k; ++i) {
		cin >> x >> y;
		if (!y) cut.emplace_back (x);
		else lim[x] = y;
	}
	cut.emplace_back (-1);
	sort (a + 1, a + 1 + n);
	sort (cut.begin (), cut.end ());
	for (int i = 0; i < cut.size (); ++i) {
		p[i] = cut[i] + 1;
		if (!lim.count (p[i])) lim[p[i]] = LLONG_MAX;
	}
	int mov = 0;
	for (int i = 1, id; i <= n; ++i) {
		id = upper_bound (cut.begin (), cut.end (), a[i]) - cut.begin () - 1;
		++cnt[p[id]];
		mov += a[i] - p[id];
		if (cnt[p[id]] >= lim[p[id]]) {
			++p[id];
			if (!lim.count (p[id])) lim[p[id]] = LLONG_MAX;
		}
	}
	cout << (mov & 1 ? 0 : 1) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}