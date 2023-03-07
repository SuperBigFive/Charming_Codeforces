#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
int a[maxn], ans[maxn];
set <int> s;

void init () {s.clear ();}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i)
	s.insert (i), cin >> a[i], ans[i] = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i] >= a[i - 1]) continue;
		int p = *s.lower_bound (a[i - 1] - a[i]);
		ans[p] = i;
		s.erase (p);
	}
	for (int i = 1; i <= n; ++i)
	cout << ans[i] << " \n"[i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}