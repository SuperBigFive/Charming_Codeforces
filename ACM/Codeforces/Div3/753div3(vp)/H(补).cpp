#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e6 + 5;

int t, n;
vector <array <int, 4> > dish[N]; 

void init () {}

void charming () {
	init ();
	cin >> n;
	set <int> sum;
	vector <array <int, 4> > d (n);
	for (int i = 0, s; i < n; ++i) {
		d[i][0] = i;
		cin >> d[i][1] >> d[i][2] >> d[i][3];
		s = d[i][1] + d[i][2] - d[i][3];
		sum.insert (s);
		dish[s].emplace_back (d[i]);
	}
	int res = 0;
	auto get_lr = [&] (array <int, 4> x) -> pair <int, int> {
		int l = max (0ll, x[1] - x[3]);
		int r = x[1] - max (0ll, x[3] - x[2]);
		return make_pair (l, r);
	};
	vector <pair <int, int> > ans (n);
	for (auto it : sum) {
		sort (dish[it].begin (), dish[it].end (), [] (array <int, 4> &x,
		array <int, 4> &y) {return x[1] < y[1];});
		for (int i = 0, cr = -1; i < dish[it].size (); ++i) {
			auto [l, r] = get_lr (dish[it][i]);
			if (l > cr) ++res, cr = r;
			ans[dish[it][i][0]].first = dish[it][i][1] - cr;
			ans[dish[it][i][0]].second = dish[it][i][3] - dish[it][i][1] + cr;
		}
		dish[it].clear ();
	}
	cout << res << endl;
	for (int i = 0; i < n; ++i) cout << ans[i].first << " " << ans[i].second << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}