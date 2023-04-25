#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int mod = 1e9 +7;

int t, n, x, pos;
ll lef, rig;

void charming () {
	cin >> n >> x >> pos;
	int l = 0, r = n, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (mid <= pos) ++lef, l = mid + 1;
		else ++rig, r = mid;
	}
	ll ans = 1;
	ll small = x - 1, big = n - x;
	--lef;
	for (int i = 1; i <= lef; ++i) {
		ans = (ans * small) % mod;
		--small;
	}
	for (int i = 1; i <= rig; ++i) {
		ans = (ans * big) % mod;
		--big;
	}
	ll res = n - lef - rig - 1;
	for (int i = 1; i <= n - lef - rig - 1; ++i) {
		ans = (ans * res) % mod;
		--res;
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}