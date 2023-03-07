#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int t, n, k;
bool flag1, flag2;
string s;

void init () {}

int check (int l1, int r1, int l2, int r2) {
	if (l1 == -1) return 0;
	if (l2 == -1) {
		if (r1 - l1 + 1 > k) return 2;
		if (r1 - l1 + 1 == k && flag2) return 2;
		if (r1 - l1 + 1 == k) flag2 = true;
		return 0;
	}
	if (flag1) return 2;
	flag1 = true;
	if (r1 - l1 + 1 == k) return 1;
	if (r1 - l1 + 1 < k) return 0;
	int len = r2 - l2 + 1;
	if (len > k) return 0;
	if (len == k) return 1;
	if (l1 == l2 || r1 == r2) return 1;
	return 2;
}

void charming () {
	flag1 = flag2 = false;
	cin >> n >> k;
	cin >> s;
	s += '0';
	int mn = -1, mx = -1;
	for (int i = 0; i < s.size (); ++i) {
		if (s[i] != '1') continue;
		if (mn == -1) mn = i;
		mx = i;
	}
	if (mn == -1) mn = 0, mx = s.length ();
	else {
		while (s[mn] != '0' && mn > 0) --mn;
		while (s[mx] != '0' && mx < s.length ()) ++mx;
	}
	int l1 = -1, r1 = -1, l2 = -1, r2 = -1, res = 0;
	for (int i = mn; i < mx; ++i) {
		if (s[i] == '0') {
			res += check (l1, r1, l2, r2);
			l1 = r1 = l2 = r2 = -1;
			continue;
		}
		if (s[i] == '1') {
			if (l2 == -1) l2 = i;
			r2 = i;
		}
		if (l1 == -1) l1 = i;
		r1 = i;
	}
	res += check (l1, r1, l2, r2);
	cout << (((res == 1 || (!res && flag2)) && !(flag1 && flag2))? "Yes" : "No") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}