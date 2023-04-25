#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
mt19937 rnd (random_device {}());

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <bool> ok (n);
	vector <int> pre_rec (n);
	vector <array <int, 4> > ans (n);
	vector <array <int, 5> > rec (n);
	for (int i = 0; i < n; ++i) {
		cin >> rec[i][1] >> rec[i][3] 
		>> rec[i][2] >> rec[i][4];
		rec[i][0] = i;
	}
	sort (rec.begin (), rec.end (), [] (array <int, 5> &x,
	array <int, 5> &y) {return x[3] < y[3];});
	int last1 = 0, last2 = 0, last12 = 0, last_id = 0, res = 0;
	vector <int> pre;
	vector <pair <int, int> > blank;
	for (auto &[id, u, d, l, r] : rec) {
		if (u == 1 && d == 1) {
			if (last1 >= r) {ok[id] = true; continue;}
			l = max (l, last1 + 1);
			last1 = r;
		}
		else if (u == 2 && d == 2) {
			if (last2 >= r) {ok[id] = true; continue;}
			l = max (l, last2 + 1);
			last2 =r;
		}
		else {
			ok[id] = true;
			if (last12 >= r) continue;
			if (l - 1 > last12) {
				blank.emplace_back (make_pair (last12 + 1, l - 1));
				pre.emplace_back (last_id);
			}
			ans[id][0] = u, ans[id][1] = d;
			if (l <= last12 + 1) pre_rec[id] = last_id;
			else pre_rec[id] = id;
			ans[id][2] = max (last12 + 1, l);
			ans[id][3] = r;
			last12 = r;
			res += (ans[id][3] - ans[id][2] + 1) * 2;
			last_id = id;
		}
	}
	if (last12 < 1e9) {
		blank.emplace_back (make_pair (last12 + 1, 1e9));
		pre.emplace_back (last_id);
	}
	for (auto &[id, u, d, l, r] : rec) {
		if (ok[id]) continue;
		auto p = upper_bound (blank.begin (), blank.end (),
		make_pair (l, 0), [] (pair <int, int> x, pair <int, int> y) {
		return x.first < y.first;}) - blank.begin ();
		if (p && blank[p - 1].second >= l) --p;
		int mx = 0, key = 0, sum = 0, dec = 0, q = 0;
		vector <int> rec_id;
		for (int i = p, len; i < blank.size () && blank[i].first <= r; ++i) {
			len = min (r, blank[i].second) - max (l, blank[i].first) + 1;
			sum += len;
			if (i > p) rec_id.emplace_back (pre[i]);
			q = i;
		}
		if (!sum) continue;
		l = max (l, blank[p].first);
		r = min (r, blank[q].second);
		for (auto it : rec_id) {
			while (true) {
				if (u == 1) ans[it][0] = 2;
				else ans[it][1] = 1;
				if (it == pre_rec[it]) break;
				it = pre_rec[it];
			}
		}
		res += sum;
		ans[id][0] = u, ans[id][1] = d;
		ans[id][2] = l, ans[id][3] = r;
	}
	cout << res << endl;
	for (int i = 0; i < n; ++i) {
		cout << ans[i][0] << " " << ans[i][2] << " "
		<< ans[i][1] << " " << ans[i][3] << endl;
	}
}


signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}