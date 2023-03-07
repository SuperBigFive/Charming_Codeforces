#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
#define format pair <int, pair <int, int > >
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
ll pow2[61];

void init () {
	
}

void build_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i <= 60; ++i) {
		pow2[i] = pow2[i - 1]  * 2;
	}
}

ll get_one (ll num) {
	ll res = 0;
	while (num) {
		if (num & 1) ++res;
		num >>= 1;
	}
	return res;
}

void charming () {
	init ();
	cin >> m >> n;
	int d = get_one (n);
	//ll ans = pow2[m - d] * (pow2[d] - 1);
	ll ans = pow2[m] - 1;
	if (m == 1) {
		if (n == 1) cout << 2 << endl;
		else cout << 1 << endl;
		return;
	}
	if (!n) ++ans;
	cout << ans << endl; 
}

signed main () {
	cin >> t;
	build_pow2 ();
	while (t--) charming ();
	return 0;
}