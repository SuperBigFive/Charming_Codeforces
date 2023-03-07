#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
string s;

void init () {}

int check (string &tmp) {
	ll res = 0;
	int p = 1, q = n, pp = 1, qq = n;
	while (tmp[p] != '1') ++p;
	while (tmp[q] != '1') --q;
	while (tmp[pp] == '0') ++pp;
	while (tmp[qq] == '0') --qq;
	res = max (pp - 1, n - qq);
	for (int i = p + 1; i < q; ++i) {
		if (tmp[i] == '1') {
			if (tmp[i - 1] == '0' && tmp[i + 1] == '0') {
				int l = i - 1, r = i + 1;
				while (l - 1 >= 1 && tmp[l - 1] == '0') --l;
				while (r + 1 <= n && tmp[r + 1] == '0') ++r;
				if (r - i > i - l) tmp[i + 1] = '1', ++i;
				else tmp[i - 1] = '1';
			}
			else if (tmp[i - 1] == '0') tmp[i - 1] = '1';
			else if (tmp[i + 1] == '0') tmp[i + 1] = '1', ++i;
		}
	}
	//cout << tmp << endl;
	for (int i = p, cnt = 0; i <= q; ++i) {
		if (tmp[i] == '0') ++cnt;
		else {
			res = max (res, (cnt + 1) / 2);
			cnt = 0;
		}
	}
	return res;
}

void charming () {
	init ();
	cin >> n >> s;
	s = '0' + s + '0';
	int p = 1, q = n;
	while (s[p] == '0')	++p;
	while (s[q] == '0') --q;
	bool ok = true;
	for (int i = 1; i <= n; ++i) if (s[i] == '0') {
		ok = false;
		break;
	}
	if (ok) {
		cout << 0 << endl;
		return;
	}
	if (p == q) {
		cout << min (max (p, n - q), max (p - 1, n - q + 1)) << endl;
		return;
	}
	char old1, old2;
	ll res = INT_MAX;
	int sigp[2] = {1, -1}, sigq[2] = {1, -1};
	string tmp;
	for (int i = 0; i <= 1; ++i) {
		for (int j = 0; j <= 1; ++j) {
			tmp = s;
			if (tmp[p + sigp[i]] == '0') tmp[p + sigp[i]] = '2';
			if (tmp[q + sigq[j]] == '0') tmp[q + sigq[j]] = '2';
			res = min (res, check (tmp) + 1);
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}