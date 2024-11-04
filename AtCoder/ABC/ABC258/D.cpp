#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;

int n, x;
ll a[maxn], b[maxn];
ll cost[maxn];

void charming () {
	cin >> n >> x;
	for (int i = 1; i <= n ;++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= min (x, n); ++i) {
		cost[i] = cost[i - 1] + a[i] + b[i]; 
	}
	ll ans = cost[1] + b[1] * (x - 1);
	for (int i = 1; i <= min (x, n); ++i) {
		ans = min (ans, cost[i] + b[i] * (x - i));
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
