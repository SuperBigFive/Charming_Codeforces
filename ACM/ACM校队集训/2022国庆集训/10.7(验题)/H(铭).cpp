#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e3 + 5;
const int p_ = 114514;
const int mod = 125343427643;

int n, m;
int cham[15], player[15];
char s[maxn];
set <int> ok;

void init () {}

ll get_hash () {
	int len = strlen (s + 1);
	ll res = 0;
	for (int i = 1; i <= len; ++i) {
		res = (res * p_ + s[i] - 'a') % mod;
	}
	return res;
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 5; ++j) {
			cin >> s + 1;
			ok.insert (get_hash ());
		}
	}
	cin >> m;
	for (int i = 1, pos; i <= m; ++i) {
		cin >> s + 1;
		cin >> pos;
		if (ok.count (get_hash ())) ++cham[pos];
		else ++player[pos];
	}
	ll res = 0;
	while (true) {
		int mn = INT_MAX, id;
		for (int i = 1; i <= 5; ++i) {
			if (player[i] < mn && cham[i]) {
				mn = player[i];
				id = i;
			}
		}
		if (mn == INT_MAX) break;
		for (int i = 1; i <= 5; ++i) {
			if (i == id) {
				--cham[i];
				continue;
			}
			--player[i];
			if (player[i] < 0) {
				if (cham[i] > 0) --cham[i], player[i] = 0;
				else {
					cout << res << endl;
					return;
				}
			}
		}
		++res;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}