#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> a (n * m);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end (), [] (int x, int y) {return x > y;});
	int ans1 = a[0] * (n * m) - a[0] - a[n * m - 2] * (m - 1) - a[n * m - 1] * ((n - 1) * m);
	int ans2 = a[0] * (n * m) - a[0] - a[n * m - 2] * (n - 1) - a[n * m - 1] * (n * (m - 1));
	int ans3 = a[0] * ((n - 1) * m)  + a[1] * (m - 1) + a[n * m - 1] - a[n * m - 1] * (n * m);
	int ans4 = a[0] * (n * (m - 1))  + a[1] * (n - 1) + a[n * m - 1] - a[n * m - 1] * (n * m);
	cout << max ({ans1, ans2, ans3, ans4}) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}