#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;
const int p_ = 131;
const int mod = 1e9 + 7;

int n, m, tot, l, r, tmp_ra;
int ra[maxn], match[maxn], num[maxn];
int powp_[maxn], hash_s[maxn], hash_t[maxn];
char s[maxn], tmp_s[maxn], t[maxn];

void init () {tot = l = r = tmp_ra = 0;}

void modify_str () {
	for (int i = 1; i <= n; ++i) {
		s[++tot] = '#';
		s[++tot] = tmp_s[i];
	}
	s[++tot] = '#';
}

void force (int pos) {
	while (pos - tmp_ra >= 1 && pos + tmp_ra <= tot &&
	s[pos - tmp_ra] == s[pos + tmp_ra]) ++tmp_ra;
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
	for (int i = 1; i <= tot; ++i) {
		++num[i - ra[i] + 1];
		--num[i + 1];
	}
	for (int i = 1; i <= tot; ++i) {
		num[i] += num[i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		num[i] = num[i << 1];
	}
}

void get_powp_ () {
	powp_[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		powp_[i] = powp_[i - 1] * p_ % mod;
	}
}

void get_hash_st () {
	for (int i = 1, num; i <= n; ++i) {
		num = tmp_s[i] - 'a' + 1;
		hash_s[i] = (hash_s[i - 1] * p_ + num) % mod;
	}
	for (int i = 1, num; i <= m; ++i) {
		num = t[i] - 'a' + 1;
		hash_t[i] = (hash_t[i - 1] * p_ + num) % mod;
	}
}

int get_hash (int be, int en) {
	return (hash_s[en] - (hash_s[be - 1] * powp_[en - be + 1]) % mod + mod) % mod; 
}

void get_match () {
	reverse (tmp_s + 1, tmp_s + 1 + n);
	get_hash_st ();
	int l, r, mid, hash_s;
	for (int i = 1; i <= n; ++i) {
		l = 1, r = m;
		while (l <= r) {
			mid = (l + r) >> 1;
			hash_s = get_hash (i, i + mid - 1);
			if (hash_s == hash_t[mid]) match[i] = mid, l = mid + 1;
			else r = mid - 1;
		}
	}
	reverse (match + 1, match + 1 + n);
}

void charming () {
	init ();
	cin >> tmp_s + 1;
	cin >> t + 1;
	n = strlen (tmp_s + 1);
	m = strlen (t + 1);
	modify_str ();
	manecher ();
	get_match ();
	ll res = 0;
	for (int i = 1; i <= n; ++i) 
	res += num[i] * match[i - 1];
	cout << res << endl;
}

signed main () {
	//freopen ("input.in", "r", stdin);
	get_powp_ ();
	charming ();
	return 0;
}