#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n, k;
ll pow10[15];

void init () {}

void get_pow10 () {
	pow10[0] = 1;
	for (int i = 1; i < 10; ++i)
	pow10[i] = pow10[i - 1] * 10;
}

ll f (ll num, int id, vector <int> &used) {
	ll res = 0;
	for (int i = id; i >= 0; --i) {
		res += num / pow10[used[i]];
		num -= pow10[used[i]] * (num / pow10[used[i]]);
	}
	return res;
}
	
void charming () {
	init ();
	cin >> n >> k;
	vector <int> used;
	for (int i = 1, a; i <= n; ++i) {
		cin >> a;
		used.emplace_back (a);
	}
	int last = 0;
	ll res = k + 1;
	for (int i = 1; i < used.size (); ++i) {
		int cost = f (pow10[used[i]] - 1, i - 1, used);
		if (cost > k) break;
		res = pow10[used[i]] * (k - cost) + (pow10[used[i]] - 1) + pow10[used[i]];
	}
	cout << res << endl;
}

signed main () {
	get_pow10 ();
	cin >> t;
	while (t--) charming ();
	return 0;
}