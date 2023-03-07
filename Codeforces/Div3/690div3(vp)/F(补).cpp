#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 1e9 + 7;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> ans (n);
	vector <pair <int, int> > seq (n);
	for (auto &it : seq) cin >> it.first >> it.second;
	vector <pair <int, int> > seq1 = seq, seq2 = seq;
	sort (seq1.begin (), seq1.end (), [] (pair <int, int> &x,
	pair <int, int> &y) {return x.first < y.first;});
	sort (seq2.begin (), seq2.end (), [] (pair <int, int> &x,
	pair <int, int> &y) {return x.second < y.second;});
	auto cmp1 = [] (pair <int, int> x, pair <int, int> y) -> bool {
		return x.first < y.first;
	};
	auto cmp2 = [] (pair <int, int> x, pair <int, int> y) -> bool {
		return x.second <= y.second;
	};
	int res = n - 1;
	for (int i = 0; i < n; ++i) {
		auto id1 = upper_bound (seq1.begin (), seq1.end (),
		make_pair (seq[i].second, seq[i].first), cmp1) - seq1.begin ();
		auto id2 = upper_bound (seq2.begin (), seq2.end (),
		make_pair (seq[i].second, seq[i].first), cmp2) - seq2.begin ();
		ans[i] = (n - id1) + id2;
		res = min (res, ans[i]);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}