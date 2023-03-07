#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 26;

int t, n;
ll ans;
int i, j, k;
ll a[maxn], b[maxn];

void init () {
	ans = 0;
}

bool valid () {
	return abs(b[i] - a[i-1]) + abs(a[i] - b[i-1]) < abs(b[i] - b[i-1]) + abs(a[i] - a[i-1]);
}

void swap () {
	ll tmp = b[i];
	b[i] = a[i];
	a[i] = tmp;
}
void solve () {
	cin >> n;
	init ();
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i <= n; ++i) cin >> b[i];
	for (i = 2; i <= n; ++i) {
		if (valid ()) swap ();
	}
	for (i = 2; i <= n; ++i) {
		ans += abs (a[i] - a[i-1]) + abs(b[i] - b[i-1]);
	}
	cout << ans << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) solve ();
}
