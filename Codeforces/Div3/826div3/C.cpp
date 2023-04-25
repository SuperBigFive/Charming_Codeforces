#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int t, n;
int a[maxn], sum[maxn];

void init () {}

int check (int tmp) {
	int res = -1;
	int len = 0, cur = 0;
	for (int i = 1; i <= n; ++i) {
		cur += a[i];
		++len;
		if (cur == tmp) {
			res = max (res, len);
			len = cur = 0;
		}
		else if (cur > tmp) return INT_MAX;
	}
	if (!cur) return res;
	return INT_MAX;
}

void charming () {
	init ();
	cin >> n;
	ll res = n;
	for (int i = 1; i <= n; ++i) 
	cin >> a[i], sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		res = min (res, check (sum[i]));
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}