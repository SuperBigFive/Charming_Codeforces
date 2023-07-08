#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> a (N + 5), ans (N + 5, k / 2);
	vector <array <vector <int>, 2> > pos (N + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];	
		pos[a[i]][i & 1].emplace_back (i);
	}
	
	int res = (k / 2) * (n - k + 1);
	for (int type = 0; type < 2; ++type)
	for (int i = 1, l, r, siz, ql, qr; i < N; ++i) if (pos[i][type].size ()) {
		siz = pos[i][type].size ();
		for (int j = 0, p1, p2; j < siz - 1; ++j) {
			ql = max (pos[i][type][j] + 1, k / 2 + 1);
			qr = min (n - k / 2, (2 * pos[i][type][j] + k - 1) / 2);
			if (ql > qr) break;
			l = j + 1, r = siz - 1, p1 = siz - 1;
			while (l <= r) {
				int mid = l + r >> 1;
				int nmid = pos[i][type][j] + pos[i][type][mid] >> 1;
				if (nmid >= ql) r = mid - 1, p1 = mid;
				else l = mid + 1;
			}
			l = j + 1, r = siz - 1, p2 = j + 1;
			while (l <= r) {
				int mid = l + r >> 1;
				int nmid = pos[i][type][j] + pos[i][type][mid] >> 1;
				if (nmid <= qr) l = mid + 1, p2 = mid;
				else r = mid - 1;
			}
			int mid1 = pos[i][type][j] + pos[i][type][p1] >> 1;
			int mid2 = pos[i][type][j] + pos[i][type][p2] >> 1;
			if (mid1 >= ql && mid1 <= qr && mid2 >= ql && mid2 <= qr) res -= (p2 - p1 + 1);
		}
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}