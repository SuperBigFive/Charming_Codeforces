#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

bool check (int l, int r) {
	int cnt[10];
	memset (cnt, 0, sizeof cnt);
	int diff = 0;
	for (int i = l; i <= r; ++i) {
		if (!cnt[s[i] - '0']) ++diff;
		++cnt[s[i] - '0'];
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i] > diff) return false;
	}
	return true;
}

void charming () {
	cin >> n, cin >> s;
	s = '#' + s;
	int res = 0;
	for (int len = 1; len <= min (n, 100); ++len) {
		for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
			if (check (i, j)) ++res;
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}