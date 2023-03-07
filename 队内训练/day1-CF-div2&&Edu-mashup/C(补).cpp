#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;
ll x;
int wet[maxn], num[maxn];
string s;

void init () {
	for (int i = 0; i <= n; ++i)
	wet[i] = num[i] = 0;
}

void charming () {
	init ();
	cin >> n >> k >> x;
	cin >> s;
	--x;
	int cnt = 0;
	vector <ll> follow;
	for (auto it : s) {
		if (it == 'a') {
			follow.emplace_back (k * cnt);
			cnt = 0;
		}
		else ++cnt;
	}
	follow.emplace_back (k * cnt);
	ll last = 1;
	for (int i = follow.size () - 1; i >= 0; --i) {
		if (!follow[i]) continue;
		wet[i] = last;
		last = wet[i] * (follow[i] + 1);
		if (last > x || last < 0) last = x + 1;
	}
	for (int i = 0; i < follow.size () && x; ++i) {
		if (wet[i] > x || !follow[i]) continue;
		else {
			num[i] = min (follow[i], x / wet[i]);
			x -= num[i] * wet[i];
		}
	}
	for (int i = 0; i < follow.size (); ++i) {
		for (int j = 1; j <= num[i]; ++j) cout << 'b';
		if (i < follow.size () - 1) cout << 'a';
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}