#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define ppii pair <int, pii >
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

ll n, m, mid;
ll a[50];
ll dp[50][2];
map <ll, bool> exist;
vector <ll> res_l, res_r;

void init () {
	
}

void dfs (int beg, int now, int en, ll val, int st) {
	if (now > en) {
		if (!exist[val]) {
			if (!st) res_l.pb (val);
			else res_r.pb (val);
			return;
		}
	}
	dfs (beg, now + 1, en, val % m, st);
	dfs (beg, now + 1, en, (val + a[now]) % m, st);
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = a[i] % m;
	}
	sort (a + 1, a + 1 + n);
	mid = n / 2;
	dfs (1, 1, mid, 0, 0);
	exist.clear ();
	dfs (mid + 1, mid + 1, n, 0, 1);
	sort (res_l.begin (), res_l. end ());
	sort (res_r.begin (), res_r. end ());
	int p1 = 0, p2 = res_r.size () - 1;
	ll ans = 0;
	while (p1 < res_l.size () && p2 >= 0) {
		while (res_l[p1] + res_r[p2] >= m && p2 >= 0) --p2;
		if (p2 >= 0) {
			ans = max (ans, (res_l[p1] + res_r[p2]) % m);
			++p1;
		}
	}
	p1 = res_l.size () - 1, p2 = 0;
	while (p1 >= 0 && p2 < res_r.size ()) {
		while (res_l[p1] + res_r[p2] >= m && p1 >= 0) --p1;
		if (p1 >= 0) {
			ans = max (ans, (res_l[p1] + res_r[p2]) % m);
			++p2;
		}
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}