#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pip pair <int, pii> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 1e6 + 5;

inl int read () {
	char ch = getchar ();
	bool flag = true;
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = false;
		ch = getchar();
	}
	int k = ch -'0';
	while (ch = getchar(), ch <= '9' && ch >= '0') {
		k = (k << 1) + (k << 3);
		k += (ch-'0');
	}
	if (flag) return k;
	return -k;
}

inl void write (int x) {
	char F[200];
	int tmp = x > 0 ? x : -x;
	if (x < 0) putchar ('-');
	int cnt = 0;
  while (tmp > 0){
    F [cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar (F[--cnt]);
  putchar ('\n');
}

int n, q, len;
int val[maxn], cnt[maxn], bel[maxn], res[maxn];
pip query[maxn];

void charming () {
	n = read ();
	for (rg i = 1; i <= n; ++i) val[i] = read ();
	len = 1800;
	for (rg i = 1; i <= n; ++i) {
		bel[i] = (i - 1) / len + 1;
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		query[i].se.fi = read ();
		query[i].se.se = read ();
		query[i].fi = i;
	}
	sort (query + 1, query + 1 + q, [] (pip a, pip b) {
		if (bel[a.se.fi] != bel[b.se.fi]) return a.se.fi < b.se.fi;
		if (bel[a.se.fi] & 1) return a.se.se < b.se.se;
		return a.se.se > b.se.se;
	});
	rg p_l = 1, p_r = 0;
	rg ans = 0;
	for (rg i = 1; i <= q; ++i) {
		while (p_l < query[i].se.fi) {
			--cnt[val[p_l]];
			if (!cnt[val[p_l]]) --ans;
			++p_l;
		}
		while (p_l > query[i].se.fi) {
			--p_l;
			++cnt[val[p_l]];
			if (cnt[val[p_l]] == 1) ++ans;
		}
		while (p_r < query[i].se.se) {
			++p_r;
			++cnt[val[p_r]];
			if (cnt[val[p_r]] == 1) ++ans;
		}
		while (p_r > query[i].se.se) {
			--cnt[val[p_r]];
			if (!cnt[val[p_r]]) --ans;
			--p_r;
		}
		res[query[i].fi] = ans;
	}
	for (rg i = 1; i <= q; ++i) {
		write (res[i]);
	}
}

signed main () {
	charming ();
	return 0;
}