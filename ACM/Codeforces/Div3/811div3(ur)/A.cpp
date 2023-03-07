#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 2e5 + 5;

int t, n, h, m;

void init () {
	
}
void charming () {
	init ();
	cin >> n >> h >> m;
	pii clock[100];
	for (int i = 1; i <= n; ++i) {
		cin >> clock[i].fi >> clock[i].se;
	}
	sort (clock + 1, clock + 1 + n);
	bool ok = false;
	int ans_h, ans_m;
	for (int i = 1; i <= n; ++i) {
		if (clock[i].fi > h) {
			ok = true;
			ans_h = clock[i].fi - h;
			ans_m = clock[i].se - m;
			if (ans_m < 0) ans_m += 60, --ans_h;
			break;
		}
		if (clock[i].fi == h && clock[i].se >= m) {
			ok = true;
			ans_h = clock[i].fi - h;
			ans_m = clock[i].se - m;
			break;
		}
	}
	if (ok) {
		cout << ans_h << ' ' << ans_m << endl;
		return;
	}
	ans_h = clock[1].fi + 24 - h - 1;
	ans_m = clock[1].se + 60 - m;
	if (ans_m >= 60) ++ans_h, ans_m -= 60;
	if (ans_m >= 60) ++ans_h, ans_m -= 60;
	cout << ans_h << ' ' << ans_m << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}