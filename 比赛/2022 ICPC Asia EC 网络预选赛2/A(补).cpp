#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e2 + 5;

int t, n, q;
vector <int> b[maxn];

void init () {
	for (int i = 0; i < maxn; ++i) 
	b[i].clear ();
}

void small () {
	int a[maxn];
	for (int i = 1; i <= n; ++i) a[i] = b[n][i];
	cin >> q;
	for (int i = 1, p; i <= q; ++i) {
		cin >> p;
		int last = 1;
		ll res = 0;
		for (int i = n; i >= 1; --i) {
			res = (res + a[i] * last) % p;
			last = last * 10 % p;
		}
		cout << res << endl;
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= min (1ll * 100, n); ++i) {
		b[i].resize (i + 1);
		for (int j = 1, val; j <= i; ++j) {
			cin >> val;
			b[i][j] = val;
		}
	}
	if (n <= 100) {
		small();
		return;
	}
	cin >> q;
	vector <int> fac;
	for (int i = 1, p; i <= q; ++i) {
		cin >> p;
		fac.clear (), fac.resize (p);
		int last = 1, tmp = n % (p - 1);
		if (!tmp) tmp = p - 1;
		for (int j = 1; j < p; ++j) {
			fac[j] =  last % p;
			last = last * 10 % p;
		}
		ll res = 0;
		for (int j = 1; j < p; ++j) {
			res = (res + b[p - 1][j] * fac[((tmp - j + 1) + (p - 2)) % (p - 1) + 1]) % p;
		}
		cout << res << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}