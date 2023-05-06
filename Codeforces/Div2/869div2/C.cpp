#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> a (n + 5), inSeq (n + 5, -1), pre (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	vector <pair <int, int> > seq;
	for (int i = 1, j; i <= n - 2; i = j + 1) {
		j = i;
		while (j + 1 <= n && a[j + 1] <= a[j]) ++j;
		if (j - i + 1 >= 3) {
			for (int k = i; k <= j; ++k) inSeq[k] = seq.size ();
			seq.emplace_back (make_pair (i, j));
			pre[seq.size ()] = pre[seq.size () - 1] + j - i + 1;
		}
	}
	for (int i = 1, l, r, L, R, ans; i <= q; ++i) {
		cin >> l >> r;
		if (r - l + 1 <= 2 || !seq.size ()) cout << r - l + 1 << endl;
		else {
			if (inSeq[l] != -1 && inSeq[l] == inSeq[r]) {
				cout << 2 << endl;
				continue;
			}
			ans = r - l + 1;
			if (inSeq[l] != -1) ans = ans - max (2ll, seq[inSeq[l]].second - l + 1) + 2, l = seq[inSeq[l]].second + 1;
			if (inSeq[r] != -1) ans = ans - max (2ll, r - seq[inSeq[r]].first + 1) + 2, r = seq[inSeq[r]].first - 1;
			L = lower_bound (seq.begin (), seq.end (), make_pair (l, l)) - seq.begin ();
			if (L == seq.size ()) {
				cout << ans << endl;
				continue;
			}
			R = lower_bound (seq.begin (), seq.end (), make_pair (r, r)) - seq.begin () - 1;
			ans = ans - (pre[R + 1] - pre[L]) + (R - L + 1) * 2;
			cout << ans << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}