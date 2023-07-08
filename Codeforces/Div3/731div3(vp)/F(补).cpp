#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1), bel (n + 1);
	int len = sqrt (n) + 1, blo = (n - 1) / len + 1, remain = n % len;
	for (int i = 1; i <= n; ++i) cin >> a[i], bel[i] = (i - 1) / len + 1;
	int GCD = a[1];
	for (int i = 2; i <= n; ++i) GCD = __gcd (GCD, a[i]);
	int mn = GCD;
	vector <int> blo_gcd (blo + 1);
	for (int i = 1, be; i <= blo; ++i) {
		be = (i - 1) * len + 1;
		GCD = a[be];
		for (int j = be + 1; j <= min (n, be + len - 1); ++j) {
			GCD = __gcd (GCD, a[j]);
		}
		blo_gcd[i] = GCD;
	}
	vector <vector <int> > pre (blo + 1, vector <int> (len + 1));
	vector <vector <int> > suf (blo + 1, vector <int> (blo + 1));
	for (int i = 1, be, en; i <= blo; ++i) {
		be = (i - 1) * len + 1, en = min (n, i * len);
		GCD = a[en];
		for (int j = en; j >= be; --j) {
			GCD = __gcd (GCD, a[j]);
			pre[i][en - j + 1] = GCD;
		}
	}
	for (int i = 1; i <= blo; ++i) {
		GCD = blo_gcd[i];
		for (int j = 0; j <= blo; ++j) {
			GCD = __gcd (GCD, blo_gcd[(i + j - 1) % blo + 1]);
			suf[i][j] = GCD;
		}
	}
	int res = 0;
	for (int i = 1, be, en; i <= n; ++i) {
		GCD = a[i], en = min (n, bel[i] * len);
		if (pre[bel[i]][en - i + 1] <= mn) {
			for (int j = i; j <= en; ++j) {
				GCD = __gcd (GCD, a[j]);
				if (GCD <= mn) {
					res = max (res, (j - i + n) % n);
					break;
				}
			}
			continue;
		}
		else GCD = pre[bel[i]][en - i + 1];
		int l = 0, r = blo - 1, k = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (__gcd (GCD, suf[bel[i] % blo + 1][mid]) <= mn) r = mid - 1, k = mid;
			else l = mid + 1;
		}
		if (k > 0) GCD = __gcd (GCD, suf[bel[i] % blo + 1][k - 1]);
		be = ((bel[i] + k) % blo) * len + 1;
		en = min (n, be + len - 1);
		for (int j = be; j <= en; ++j) {
			GCD = __gcd (GCD, a[j]);
			if (GCD <= mn) {
				res = max (res, (j - i + n) % n);
				break;
			}
		}
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
	