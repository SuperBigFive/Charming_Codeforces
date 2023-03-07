#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n), b (n);
	for (auto &it : a) cin >> it;
	b = a;
	int mn2 = INT_MAX, mn3 = INT_MAX;
	int sum2 = 0, sum3 = 0;
	for (int i = 0; i < n; ++i) {
		int cnt2 = 0, cnt3 = 0;
		while (!(b[i] % 2)) b[i] /= 2, ++cnt2;
		while (!(b[i] % 3)) b[i] /= 3, ++cnt3;
		mn2 = min (mn2, cnt2);
		mn3 = min (mn3, cnt3);
		sum2 += cnt2, sum3 += cnt3;
	}
	for (auto &it : b) if (it != b.back ()) {
		cout << -1 << endl;
		return;
	}
	cout << sum2 + sum3 - n * (mn2 + mn3) << endl;
}

signed main () {
	charming ();
	return 0;
}