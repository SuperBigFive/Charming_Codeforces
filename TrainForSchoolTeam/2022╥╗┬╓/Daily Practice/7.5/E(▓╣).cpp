#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int maxn = 2e6 + 5;
const int maxm = 2e6 + 5;

int n, m;
ll a[maxn], b[maxn];
ll res[maxm];
ll tmp[maxn];
ll diff[maxm];
ll vv[maxm];
map <ll, ll> mm;

ll gcd (ll x, ll y) {
	if (y) return gcd (y, x % y);
	else return x;
}

void charming () {
	//init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];
	if (n >= 2) {
		sort (a + 1, a + 1 + n);
		for (int i = 2; i <= n; ++i) {
			diff[i] = a[i] - a[i-1];
		}
		ll GCD = diff[2];
		for (int i = 3; i <= n; ++i) {
			GCD = gcd (diff[i], GCD);
		}
		ll ans = GCD;
		for (int i = 1; i <= m; ++i) {
			ans = gcd (b[i] + a[1], GCD);
			cout << ans << " ";
		}
	}
	else {
		for (int i = 1; i <= m; ++i) {
			cout << a[1] + b[i] << " ";
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming (); 
	return 0;
}
