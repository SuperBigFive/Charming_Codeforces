#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int t, n, k;
ll val[maxn], sum[maxn];

void init () {
}

void charming () {
	init ();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		sum[i] = sum[i - 1] + val[i] - k;
	}
	ll mmax = 0, id = 0;
	for (int i = 1; i <= n; ++i) {
		if (sum[i] > mmax) {
			mmax = sum[i];
			id = i;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		ll tmp = sum[i];
		int j = 1;
		while (j <= 50 && i + j <= n) {
			tmp += (val[i + j] >> j);
			++j;
		}
		ans = max (ans, tmp);
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