#include <bits/stdc++.h>
#define ll  long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, w, h;

void init () {}

void charming () {
	init ();
	cin >> n >> w >> h;
	vector <pair <int, int> > seq_cake, seq_dis;
	for (int i = 0, a; i < n; ++i) {
		cin >> a;
		seq_cake.emplace_back (make_pair (a - w, a + w));
	}
	int l = 0, r = 0;
	for (int i = 0, b; i < n; ++i) {
		cin >> b;
		seq_dis.emplace_back (make_pair (b - h, b + h));
		if (seq_dis[i].first < seq_cake[i].first) l = max (l, seq_cake[i].first - seq_dis[i].first);
		if (seq_dis[i].second > seq_cake[i].second) r = max (r, seq_dis[i].second - seq_cake[i].second);
	}
	if (!l && !r) cout << "YES" << endl;
	else if (l && r) cout << "NO" << endl;
	else {
		bool ok = true;
		int mov = -l + r;
		for (int i = 0; i < n; ++i) {
			if (seq_cake[i].first + mov > seq_dis[i].first ||
			seq_cake[i].second + mov < seq_dis[i].second) {
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}