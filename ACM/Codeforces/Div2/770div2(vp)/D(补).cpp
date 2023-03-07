#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

int ask (int i, int j, int k) {
	int dis;
	cout << "? " << i << " " << j << " " << k << endl;
	fflush (stdout);
	cin >> dis;
	return dis;
}

void ans (int i, int j) {
	cout << "! " << i << " " << j << endl;
	fflush (stdout);
}

void check (vector <pair <int, int> > &val_id) {
	for (int j = 0; j < 4; ++j) {
		vector <int> chk;
		for (int k = 0; k < 4; ++k) {
			if (k == j) continue;
			chk.emplace_back (val_id[k].second);
		}
		val_id[j].first = ask (chk[0], chk[1], chk[2]);
	}
	sort (val_id.begin (), val_id.end ());
}

void charming () {
	init ();
	cin >> n;
	pair <int, int> res = {1, 2};
	for (int i = 3; i < n; i += 2) {
		vector <pair <int, int> > val_id (4);
		val_id[0].second = res.first;
		val_id[1].second = res.second;
		val_id[2].second = i;
		val_id[3].second = i + 1;
		check (val_id);
		res.first = val_id[0].second;
		res.second = val_id[1].second;
	}
	if (n & 1) {
		vector <pair <int, int> > val_id (4);
		val_id[0].second = res.first;
		val_id[1].second = res.second;
		val_id[2].second = n;
		for (int i = 1; i < n; ++i) {
			if (i != res.first && i != res.second) {
				val_id[3].second = i;
				break;
			}
		}
		check (val_id);
		res.first = val_id[0].second;
		res.second = val_id[1].second;
	}
	ans (res.first, res.second);
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}