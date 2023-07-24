#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	priority_queue <int, vector <int>, greater <int> > pq;
	ll ans = 0;
	for (int i = 0, last = 0, a, delta; i < n; ++i) {
		cin >> a, a %= k;
		delta = a - last;
		if (delta == 0) continue;
		else if (delta < 0) pq.push (delta + k);
		else {
			pq.push (delta);
			ans += pq.top ();
			pq.pop ();
		}
		last = a;
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}