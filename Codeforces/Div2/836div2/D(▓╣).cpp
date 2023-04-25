#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

pair <ll, pair <ll, ll> > get (ll k) {
	ll a = (k * k - (n - 1) * (n - 2) / 2 - k) / n;
	ll l = n * a + k + (n - 1) * (n - 2) / 2;
	ll r = n * a + k + (2 * k - n + 1) * (n - 2) / 2;
	if (r < k * k) return make_pair (-1, make_pair (-1, -1));
	return make_pair (a, make_pair (l, r));
}

vector <int> solve (ll cnt, ll mx, ll sum) {
	vector <int> ans (n + 1);
	int p1 = mx, p2 = cnt, s = 0;
	while (p2 > 0) {
		while (p1 > 0 && p2 * (p2 - 1) / 2 + s + p1 > sum) --p1;
		ans[p2 + 1] = p1, --p2;
		s += p1, --p1;
	}
	return ans;
}

void charming () {
	init ();
	cin >> n;
	if (n == 2) {
		cout << 3 << " " << 1 << endl;
		return;
	}
	ll k = (n - 2) << 1;
	pair <ll, pair <ll, ll> > cur;
	vector <int> ans (n + 1);
	while (true) {
		cur = get (k);
		if (cur.first == -1) {++k; continue;}
		ans = solve (n - 2, k - 1, k * k - k - n * cur.first);
		break;
	}
	ans[1] = 0, ans[n] = k;
	for (int i = 1; i <= n; ++i) {
		cout << cur.first + ans[i] << " \n"[i == n];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
