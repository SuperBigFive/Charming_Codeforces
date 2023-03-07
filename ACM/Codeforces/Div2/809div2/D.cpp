#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 3e3 + 5;

int t, n, k;
ll ans;
int a[maxn], p[maxn];
bool exist[maxn];
vector <int> val;

void init () {
	for (int i = 1; i <= 3000; ++i) {
		exist[i] = false;
	}
	val.clear ();
}

void check (int num) {
	int tmp_k = 1;
	ll mmin = LONG_MAX;
	for (int i = 1; i <= n; ++i) {
		tmp_k = 1;
		if (a[i] / k > num) return;
		while (a[i] / tmp_k > num && tmp_k <= k) ++tmp_k;
		mmin = min (mmin, a[i] / tmp_k);
	}
	ans = min (ans, num - mmin);
	return;
}

void charming () {
	init ();
	cin >> n >> k;
	ll tmp;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (k == 1) {
		cout << a[n] - a[1] << endl;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			tmp = a[i] / j;
			if (!exist[tmp]) val.pb (tmp);
			exist[tmp] = true;
		}
	}
	sort (val.begin (), val.end ());
	ans = LONG_MAX;
	for (auto it : val) {
		check (it);
	}
	/*int l = 0, r = val.size () - 1, mid;
	ans = LONG_MAX;
	while (l < r - 1) {
		mid = (l + r) / 2;
		if (!check (mid)) l = mid;
		else r = mid;
	}*/
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}