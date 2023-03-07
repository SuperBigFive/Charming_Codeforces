#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn], b[maxn];
int cnta[10], cntb[10];
bool visa[maxn], visb[maxn];

void init () {
	fill (cnta, cnta + 10, 0);
	fill (cntb, cntb + 10, 0);
	for (int i = 1; i <= n; ++i) visa[i] = visb[i] = false;
}

int get (int v) {
	int ans = 0;
	while (v) {
		++ans;
		v /= 10;
	}
	return ans;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	sort (a + 1, a + 1 + n);
	sort (b + 1, b + 1 + n);
	int ans = 0;
	for (int i = 1, j = 1; i <= n && j <= n; ++i) {
		while ((b[j] < a[i] || visb[j]) && j <= n) ++j;
		if (b[j] > a[i] || j > n) continue;
		visa[i] = visb[j] = true;
	}
	for (int i = 1; i <= n; ++i) {
		if (!visa[i]) {
			if (a[i] < 10) ++cnta[a[i]];
			else ++ans, ++cnta[get (a[i])];
		}
		if (!visb[i]) {
			if (b[i] < 10) ++cntb[b[i]];
			else ++ans, ++cntb[get (b[i])];
		}
	}
	for (int i = 2, tmp; i < 10; ++i) {
		ans += abs (cnta[i] - cntb[i]);
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}