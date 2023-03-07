#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int n, m, w, tot;
int sa[maxn], rk[maxn], height[maxn];
int id[maxn], old_rk[maxn], cnt[maxn];
int s[maxn];

void init () {}

void key2_sort () {
	tot = 0;
	for (int i = n; i > n - w; --i) id[++tot] = i;
	for (int i = 1; i <= n; ++i) if (sa[i] - w > 0) {
		id[++tot] = sa[i] - w;
	}
}

void key1_sort () {
	fill (cnt + 1, cnt + 1 + m, 0);
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
	for (int i = 1;i <= n;i++) rk[sa[i]] = i;
	for (int i = 1, k = 0; i <= n; ++i) {
		if (rk[i] == 1) continue;
		if (k) --k;
		while (s[sa[rk[i]] + k] == s[sa[rk[i] - 1] + k]) ++k;
		height[rk[i]] = k;
	}
}

bool check (int k) {
	int mn = sa[1], mx = sa[1];
	for (int i = 2; i <= n; ++i) {
		if (height[i] >= k) {
			mx = max (mx, sa[i]);
			mn = min (mn, sa[i]);
			if (mx - mn > k) return true;
			continue;
		}
		mn = sa[i], mx = sa[i];
	}
	return false;
}

void charming () {
	char ch1, ch2;
	int num1, num2;
	cin >> num1;
	for (int i = 1; i < n; ++i) {
		cin >> num2;
		s[i] = num2 - num1 + 90;
		++cnt[rk[i] = s[i]];
		num1 = num2;
	}
	--n, m = 300;
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
	
	for (w = 1; w < n && tot < n; w <<= 1, m = tot) {
		key2_sort ();
		key1_sort ();
		update ();
	}
	
	get_height ();	
	int l = 1, r = n, res = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	if (res < 4) cout << 0 << endl;
	else cout << res + 1 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> n;
	charming ();
	return 0;
}