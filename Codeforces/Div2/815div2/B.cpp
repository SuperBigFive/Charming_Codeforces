#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k, b;
ll s;
ll ans[maxn];

void init () {
	
}

void charming () {
	cin >> n >> k >> b >> s;
	if (k != 1) {
		if (k * b > s || n * (k - 1) < s - k * b) {
			cout << -1 << endl;
			return;
		}
		ll res;
		if (k * b + k - 1 >= s) 
		cout << s << ' ', res = 0;
		else cout << k * b + k - 1 << ' ', res = s - k * b - k + 1;
		for (int i = 2; i <= n; ++i) {
			if (res >= k) cout << k - 1 << ' ', res -= k - 1;
			else cout << res << ' ', res = 0;
		}
		cout << endl;
	}
	else {
		if (b != s) {
			cout << -1 << endl;
			return;
		}
		cout << b << ' ';
		for (int i = 2; i <= n; ++i) {
			cout << 0 << ' ';
		}
		cout << endl;
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