#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int n, len, m, w, tot;
int bel[maxn];
int sa[maxn], rk[maxn], height[maxn];
int id[maxn], old_rk[maxn], cnt[maxn];
string s, t, res;
set <int> vis;

void init () {
	tot = 0;
	fill (cnt + 1, cnt + 1 + 300, 0);
	s.clear ();
	vis.clear ();
	res.clear ();
}

void key2_sort () {
	tot = 0;
	for (int i = len; i > len - w; --i) id[++tot] = i;
	for (int i = 1; i <= len; ++i) if (sa[i] > w) {
		id[++tot] = sa[i] - w;
	}
}

void key1_sort () {
	fill (cnt + 1, cnt + 1 + m, 0);
	for (int i = 1; i <= len; ++i) ++cnt[rk[id[i]]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = len; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
}

void update () {
	tot = 0;
	memcpy (old_rk, rk, sizeof rk);
	for (int i = 1; i <= len; ++i) {
		if (old_rk[sa[i]] == old_rk[sa[i - 1]]
		&& old_rk[sa[i] + w] == old_rk[sa[i - 1] + w])
		rk[sa[i]] = tot;
		else rk[sa[i]] = ++tot;
	}
}

void get_height () {
	for (int i = 1, k = 0; i <= len; ++i) {
		if (rk[i] == 1) continue;
		if (k) --k;
		while (s[sa[rk[i]] + k] == s[sa[rk[i] - 1] + k]) ++k;
		height[rk[i]] = k;
	}
}

bool check (int mid) {
	vis.clear ();
	for (int i = 2; i <= len; ++i) {
		if (height[i] < mid) vis.clear ();
		else {
			vis.insert (bel[sa[i]]);
			vis.insert (bel[sa[i - 1]]);
			if (vis.size () >= n) {
				res = s.substr (sa[i], mid);
				return true;
			}
		}
	}
	return false;
}

void charming () {
	init ();
	s += '#';
	int mn = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		len = t.size ();
		s += '#';
		for (int j = s.size (); j <= s.size () + len - 1; ++j)
		bel[j] = i;
		s += t;
		mn = min (mn, len);
	}
	m = 300, len = s.size () - 1;
	for (int i = 1; i <= len; ++i) ++cnt[rk[i] = s[i]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = len; i >= 1; --i) sa[cnt[rk[i]]--] = i;
	
	for (w = 1; w < len && tot < len; m = tot, w <<= 1) {
		key2_sort ();
		key1_sort ();
		update ();
	}
	
	get_height ();
	int l = 0, r = mn, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	if (ans && res != "#") cout << res << endl;
	else cout << "IDENTITY LOST" << endl;
}

signed main () {
	while (true) {
		cin >> n;
		if (!n) break;
		charming ();
	}
	return 0;
}