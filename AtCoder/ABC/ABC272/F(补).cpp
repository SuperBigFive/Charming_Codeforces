#include <bits/stdc++.h>
#define ll long long
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

void charming () {
	cin >> n;
	cin >> s + 1, cin >> t + 1;
	int old_n = n;
	for (int i = n + 1; i <= 2 * n - 1; ++i)
	s[i] = s[i - n], t[i] = t[i - n];
	s[2 * n] = '#';
	for (int i = 1; i <= 2 * n - 1; ++i) 
	s[2 * n + i] = t[i];
	s[4 * n] = 'z' + 1;
	n = 4 * n;
	m = 300;
	for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
	
	for (w = 1; w < n; m = tot, w <<= 1) {
		key2_sort ();
		key1_sort ();
		update ();
		if (tot == n) {
			for (int i = 1; i <= n; ++i) sa[rk[i]] = i;
			break;
		}
	}
	
	int tmp = old_n;
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (sa[i] <= old_n) res += tmp;
		else if (sa[i] > old_n * 2 && sa[i] <= old_n * 3) --tmp;
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}