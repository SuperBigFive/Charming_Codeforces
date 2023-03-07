#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e7 + 5;

int n, tot, l, r, tmp_ra;
int ra[maxn << 1];
char str[maxn << 1], tmp_str[maxn];

void init () {tot = l = r = tmp_ra = 0;}

void modify_str () {
	for (int i = 1; i <= n; ++i) {
		str[++tot] = '#';
		str[++tot] = tmp_str[i];
	}
	str[++tot] = '#';
}

void force (int pos) {
	while (pos - tmp_ra >= 1 && pos + tmp_ra <= tot &&
	str[pos - tmp_ra] == str[pos + tmp_ra]) ++tmp_ra;
}

void update (int pos) {
	if (r < pos + tmp_ra - 1) {
		r = pos + tmp_ra - 1;
		l = pos - tmp_ra + 1;
	}
	ra[pos] = tmp_ra;
}

void manecher () {
	for (int i = 1; i <= tot; ++i) {
		tmp_ra = i > r ? 1 : min (ra[l + r - i], r - i + 1);
		force (i);
		update (i);
	}
}

void charming () {
	init ();
	cin >> tmp_str + 1;
	n = strlen (tmp_str + 1);
	modify_str ();
	manecher ();
	int res = 1;
	for (int i = 1; i <= tot; ++i) {
		res = max (res, ra[i] - 1);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}