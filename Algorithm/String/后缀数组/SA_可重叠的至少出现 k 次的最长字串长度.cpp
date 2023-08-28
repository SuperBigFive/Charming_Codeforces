#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m, k, w, tot;
int sa[maxn], rk[maxn], height[maxn];
int id[maxn], old_rk[maxn], cnt[maxn];
vector <int> s;

void init () {m = maxn - 1;}

void key2_sort () {
	tot = 0;
	for (int i = n; i > n - w; --i) id[++tot] = i;
	for (int i = 1; i <= n; ++i) if (sa[i] > w) {
		id[++tot] = sa[i] - w;
	}
}

void key1_sort () {
	fill (cnt + 1, cnt + 1 + m,  0);
	for (int i = 1; i <= n; ++i) ++cnt[rk[id[i]]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
}

void update () {
	tot = 0;
	memcpy (old_rk, rk, sizeof rk);
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

bool check (int len) {
	for (int i = 1, tim = 1; i <= n; ++i) {
		if (height[i] >= len) ++tim;
		else tim = 1;
		if (tim >= k) return true;
	}
	return false;
}

void charming () {
	init ();
	cin >> n >> k;
	s.resize (n + 1);
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
	
	for (w = 1; w < n && tot < n; m = tot, w <<= 1) {
		key2_sort ();
		key1_sort ();
		update ();
	}
	
	get_height ();
	int l = k, r = n, res = k;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) l = mid + 1, res = mid;
		else r = mid - 1;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}