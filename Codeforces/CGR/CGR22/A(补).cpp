#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn], b[maxn];
int odd[maxn], even[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	ll res = 0;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		res += b[i];
		if (a[i]) odd[++cnt1] = b[i];
		else even[++cnt2] = b[i];
	}
	sort (odd + 1, odd + 1 + cnt1, [] (int &x, int &y) {
	return x > y;});
	sort (even + 1, even + 1 + cnt2, [] (int &x, int &y) {
	return x > y;});
	int com = min (cnt1, cnt2);
	for (int i = 1; i <= com; ++i) {
		res += odd[i] + even[i];
	}
	if (cnt1 == cnt2) res -= min (even[cnt2], odd[cnt1]);
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}