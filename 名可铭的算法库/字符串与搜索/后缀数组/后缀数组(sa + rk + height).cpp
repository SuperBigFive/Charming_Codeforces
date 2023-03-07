#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m, tot, w;
int sa[maxn], rk[maxn];
int id[maxn], old_rk[maxn];
int cnt[maxn], height[maxn];
char s[maxn], t[maxn];

void init () {}

void key2_sort () {
	tot = 0;
	for (int i = n; i > n - w; --i) id[++tot] = i;
	for (int i = 1; i <= n; ++i) if (sa[i] > w) {
		id[++tot] = sa[i] - w;
	}
}

void key1_sort () {
	fill_n (cnt + 1, m, 0);
	for (int i = 1; i <= n; ++i) ++cnt[rk[id[i]]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
}

void update () {
	memcpy (old_rk, rk, sizeof rk);
	tot = 0;
	for (int i = 1; i <= n; ++i) {
		if (old_rk[sa[i]] == old_rk[sa[i - 1]] 
		&& old_rk[sa[i] + w] == old_rk[sa[i - 1] + w])
		rk[sa[i]] = tot;
		else rk[sa[i]] = ++tot;
	}
}

void get_height () {
	for (int i = 1, k = 0; i <= n; ++i) {
		if (rk[i] == 1) continue;
		if (k) --k;
		while (s[sa[rk[i]] + k] == s[sa[rk[i] - 1] + k]) ++k;
		height[rk[i]] = k;
	}
}

void charming () {
	cin >> s + 1;
	n = strlen (s + 1), m = 300;
	for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
	
	for (w = 1; w < n && tot < n; w <<= 1, m = tot) {
		key2_sort ();
		key1_sort ();
		update ();
	}
	
	get_height ();
}

signed main () {
	charming ();
	return 0;
}