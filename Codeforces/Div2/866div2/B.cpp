#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s, n = s.size ();
	vector <pair <int, int> > seq;
	bool all_one = true;
	for (int i = 0, j; i < n; i = j + 1) {
		j = i;
		if (s[i] == '0') {all_one = false; continue;}
		else {
			while (j + 1 < n && s[j + 1] == s[j]) ++j;
			seq.emplace_back (make_pair (i, j));
		}
	}
	if (!seq.size ()) return void (cout << 0 << endl);
	else if (all_one) return void (cout << n * n << endl);
	int siz = seq.size (), mx_len = 0;
	for (auto [l, r] : seq) mx_len = max (mx_len, r - l + 1);
	if (siz > 1 && seq[0].first == 0 && seq[siz - 1].second == n - 1) {
		mx_len = max (mx_len, seq[0].second - seq[0].first + 1 + 
		seq[siz - 1].second - seq[siz - 1].first + 1);
	}
	int ans = 0;
	for (int i = 1; i <= mx_len; ++i)
	ans = max (ans, i * (mx_len - i + 1));
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}