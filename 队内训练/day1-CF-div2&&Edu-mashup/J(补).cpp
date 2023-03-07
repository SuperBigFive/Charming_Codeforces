#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t;

void init () {}

bool dfs (ll a, ll b, ll x) {
	if ((a < x && b < x) || !a || !b) return false;
	if (b * ((a - x) / b) == a - x || a == x || b == x) return true;
	ll c = (a - b - 1) / b + 1;
	return dfs (b, a - c * b, x);
}

void charming () {
	init ();
	ll a, b, x;
	cin >> a >> b >> x;
	if (a < b) swap (a, b);
	cout << (dfs (a, b, x) ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}