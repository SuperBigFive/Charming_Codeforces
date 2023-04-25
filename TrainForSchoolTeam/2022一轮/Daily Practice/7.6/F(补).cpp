#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e5 + 5;

int t, n, m;
ll k[maxn];
ll c[maxn];
ll cntt[maxn];
ll endd[maxn];
ll dp[maxn];
ll sum[maxn];
ll tot[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		cntt[i] = endd[i] = dp[i] = sum[i] = 0;
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> c[i];
	}
	sort (k + 1, k + 1 + n);
	int now = 1;
	ll ans = 0;
	for (int i = n; i >= 1; --i) {
		if (now <= k[i]) {
			ans += c[now];
			++now;
		}
		else ans += c[k[i]];
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
} 
