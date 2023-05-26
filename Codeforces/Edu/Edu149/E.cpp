#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = (1 << 21) + 5;
const int MOD = 998244353;

int t, k;

void init () {}

void charming () {
	init ();
	cin >> k;
	vector <int> a (N);
	for (int i = 1; i <= (1 << k); ++i) cin >> a[i];
	vector <int> level (N), fac (N);
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = (fac[i - 1] * i) % MOD;
	level[1] = 0;
	for (int i = 0, cnt = 1, cur = 1; i < k; ++i, ++cnt) {
		for (int j = 1; j <= (1 << i); ++j) level[++cur] = cnt;
	}
	int ans = 1;
	for (int i = 1, cnt1; i <= k; ++i) {
		cnt1 = 0;
		for (int j = 1, cnt2, cnt3; j <= (1 << k); j += (1 << i)) {
			cnt2 = cnt3 = 0;
			for (int p = j; p < j + (1 << i); ++p) {
				if (a[p] != -1 && level[a[p]] == (k - i + 1)) ++cnt2;
				if (a[p] != -1 && level[a[p]] < (k - i + 1)) ++cnt3;
			}
			if (cnt2 >= 2 || cnt3 >= 2) return void (cout << 0 << endl);
			else if (!cnt2) ans = (ans * (2 - cnt3)) % MOD, ++cnt1;
		}
		ans = (ans * fac[cnt1]) % MOD;
	}
	ans = ((ans % MOD) + MOD) % MOD;
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}