#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> a (n), b (m);
	map <int, int> cnt;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i], ++cnt[b[i]];
	sort (a.begin (), a.end ());
	sort (b.begin (), b.end ());
	
	auto Check = [&] (int mid) -> bool {
		int num1 = upper_bound (a.begin (), a.end (), mid) - a.begin ();
		int num2 = upper_bound (b.begin (), b.end (), mid) - b.begin ();
		num2 = m - num2 + cnt[mid];
		return num1 >= num2;
	};
	
	int l = 0, r = 1e10, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Check (mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}