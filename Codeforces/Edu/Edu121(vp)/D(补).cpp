#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

int get_add (int num) {
	if (!num) return 1;
	int old = num;
	while ((num & (-num)) != num) num -= (num & (-num));
	return num == old ? 0 : (num << 1) - old;
}

int get_mx (int num) {
	if (!num) return -1;
	while ((num & (-num)) != num) num -= (num & (-num));
	return num;
}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1), cnt (n + 1);
	vector <int> sum (n + 1), suf (n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	vector <int> b = a;
	sort (b.begin () + 1, b.end ());
	int len = unique (b.begin () + 1, b.end ()) - b.begin ();
	for (int i = 1; i <= n; ++i) 
	a[i] = lower_bound (b.begin () + 1, b.begin () + len, a[i]) - b.begin ();
	int lim = -1;
	set <int> rs;
	for (int i = 1; i <= n; ++i) lim = max (lim, a[i]), ++cnt[a[i]];
	for (int i = 1; i <= lim; ++i) sum[i] = sum[i - 1] + cnt[i];
	suf[lim] = cnt[lim];
	rs.insert (-suf[lim]);
	for (int i = lim - 1; i >= 0; --i) 
	suf[i] = suf[i + 1] + cnt[i], rs.insert (-suf[i]);
	int res = INT_MAX;
	for (int i = 0, resl, remain; i < lim; ++i) {
		if (i) rs.erase (-suf[i]);
		resl = get_add (sum[i]);
		remain = sum[lim] - sum[i];
		for (int j = 0; j < 20; ++j) {
			auto it = *(rs.lower_bound (-(1 << j)));
			if (it > 0) continue;
			it = -it;
			if (it <= (1 << j)) {
				res = min (res, resl + get_add (it) + get_add (remain - it));
			}
		}
	}
	res = min (res, 2 + get_add (sum[lim]));
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}