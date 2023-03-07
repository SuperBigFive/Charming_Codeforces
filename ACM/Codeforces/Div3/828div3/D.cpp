#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, q;
int pow2[maxn], a[maxn];
int cnt[maxn][25];

void init () {}

void get_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i <= 30; ++i)
	pow2[i] = pow2[i - 1] * 2;
}

void get_cnt () {
	for (int i = 1, tmp, p; i < maxn; ++i) {
		memcpy (cnt[i], cnt[i - 1], sizeof cnt[i]);
		tmp = i, p = 0;
		while (!(tmp & 1)) {
			tmp >>= 1;
			++p;
		}
		++cnt[i][p];
	}
}

void charming () {
	init ();
	cin >> n;
	int remain = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int tmp = a[i];
		while (!(tmp & 1)) {
			tmp >>= 1;
			++remain;
		}
	}
	int diff = n - remain, res = 0;
	for (int i = 20; i >= 1 && diff > 0; --i) {
		if (diff <= cnt[n][i] * i) {
			res += (diff - 1) / i + 1;
			diff = -1;
			break;
		}
		res += cnt[n][i];
		diff -= cnt[n][i] * i;
	}
	if (diff > 0) cout << -1 << endl;
	else cout << res << endl;
}

signed main () {
	get_pow2 ();
	get_cnt ();
	cin >> t;
	while (t--) charming ();
	return 0;
}