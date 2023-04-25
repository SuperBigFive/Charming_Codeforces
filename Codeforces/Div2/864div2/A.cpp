#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m, x, y;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> x >> y;
	
	auto get_ans = [&] (int x, int y) -> int {
		if (x == 1 && y == 1) return 2;
		if (x == n && y == m) return 2;
		if (x == 1 && y == m) return 2;
		if (x == n && y == 1) return 2;
		if (x == 1 || x == n || y == 1 || y == m) return 3;
		return 4;	
	};
	
	int ans = get_ans (x, y);
	cin >> x >> y;
	ans = min (ans, get_ans (x, y));
	
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}