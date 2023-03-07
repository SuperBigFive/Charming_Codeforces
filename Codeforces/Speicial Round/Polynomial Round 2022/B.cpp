#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m, k;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> k;
	vector <int> a (m);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end (), greater <int> ());
	int blo = n / k, remain = n % k;
	if (a[0] > blo + 1) {
		cout << "NO" << endl;
		return;
	}
	if (a[0] <= blo) {
		cout << "YES" << endl;
		return;
	}
	int cnt = 0;
	while (a[cnt] == a[0] && cnt < n) ++cnt;
	cout << (cnt <= remain ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}