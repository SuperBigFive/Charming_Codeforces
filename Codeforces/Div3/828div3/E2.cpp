#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
ll a, b, c, d;
bool ok;
vector <pair <int, int> > prim;
map <int, int> mp;

void init () {
	ok = false;
	prim.clear ();
	mp.clear ();
}

void get_prim (int num) {
	for (int j = 2; j * j <= num; ++j) {
		while (!(num % j)) {
			num /= j;
			++mp[j];
		}
	}
	if (num > 1) ++mp[num];
}

bool check (ll &x, ll &y) {
	ll kx, ky;
	kx = x * (a / x + 1);
	ky = y * (b / y + 1);
	if (kx <= c && ky <= d) {
		x = kx;
		y = ky;
		 return true;
	}
	return false;
}

void dfs (int cur, int lim, ll x, ll y) {
	if (x > c || y > d) return;
	if (cur >= lim) {
		if (check (x, y)) {
			cout << x << " " << y << endl;
			ok = true;
		}
		return;
	}
	for (int i = 1; i <= prim[cur].second; ++i)
	y *= prim[cur].first;
	for (int i = 0; i <= prim[cur].second; ++i) {
		dfs (cur + 1, lim, x, y);
		x *= prim[cur].first;
		y /= prim[cur].first;
		if (ok) return;
	}
}

void charming () {
	init ();
	cin >> a >> b >> c >> d;
	prim.emplace_back (make_pair (1, 0));
	get_prim (a);
	get_prim (b);
	for (auto it : mp) {
		prim.emplace_back (it.first, it.second);
	}
	sort (prim.begin (), prim.end ());
	int siz = prim.size ();
	dfs (0, siz, 1, 1);
	if (!ok) cout << -1 << " " << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}