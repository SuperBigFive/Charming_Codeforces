#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;
const int p = 131;
const int mod = 1e9 + 7;

int t, n;

void init () {}

void charming () {
	init ();
	string s, order;
	cin >> s, n = s.length ();
	vector <int> vis (26), hash_s (n), hash_rs (26), powp (n);
	string rs[26];
	for (int i = n - 1; i >= 0; --i) {
		if (!vis[s[i] - 'a']) order += s[i];
		vis[s[i] - 'a'] = true;
	}
	reverse (order.begin (), order.end ());
	for (int i = 0, num; i < n; ++i) {
		num = s[i] - 'a';
		if (i <= 0) hash_s[i] = num, powp[i] = 1;
		else {
			hash_s[i] = (hash_s[i - 1] * p + num) % mod;
			powp[i] = (powp[i - 1] * p) % mod;
		}
	}
	auto get_hash = [&] (int l, int r) -> int {
		if (r >= n) return -1;
		if (l <= 0) return hash_s[r];
		int res = hash_s[r] - (hash_s[l - 1] * powp[r - l + 1]);
		res = ((res % mod) + mod) % mod;
		return res;
	};
	for (int i = 0, r, ok; i < n; ++i) {
		for (int j = 0, num; j < order.size (); ++j) {
			if (order[j] == s[i]) {
				num = s[i] - 'a';
				for (int k = 0; k < j; ++k) {
					rs[k].push_back (s[i]);
					hash_rs[k] = (hash_rs[k] * p + num) % mod;
				}
				break;
			}
		}
		r = i, ok = 1;
		for (int j = 0; j < order.size (); ++j) {
			if (hash_rs[j] != get_hash (r + 1, r + rs[j].size ())) {
				ok = false;
				break;
			}
			r += rs[j].size ();
		}
		if (ok && r == n - 1) {
			cout << s.substr (0, i + 1) << 
			" " << order << endl;
			return;
		}
	}
	cout << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}