#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
int a[maxn], b[maxn];
int cnta[maxn], cntb[maxn];

void init () {
	fill (cnta + 1, cnta + 1 + n, 0);
	fill (cntb + 1, cntb + 1 + n, 0);
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		++cnta[a[i]], ++cntb[b[i]];
	}
	ll res = 1ll * n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; ++i) {
		if (!cnta[a[i]] || !cntb[b[i]]) continue;
		res -= 1ll * (cnta[a[i]] - 1) * (cntb[b[i]] - 1);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}