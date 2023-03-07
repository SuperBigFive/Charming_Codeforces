#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	auto get_sum = [] (int num) -> int {
		int res = 0;
		while (num) res += num % 10, num /= 10;
		return res;
	};
	auto get_last = [] (int num) -> int {
		int res = 1;
		while (!(num % res)) res *= 10;
		return res;
	};
	if (n & 1) {
		int x = n / 2, y = x + 1;
		if (get_sum (x) - get_sum (y) <= 1)
		return void (cout << x << " " << y << endl);
		if (get_sum (x) > get_sum (y)) swap (x, y);
		int delta = abs (get_sum (x) - get_sum (y));
		for (int i = 1;; i *= 10) {
			while (delta > 1 && (x / i % 10 < 9) && (y / i % 10 > 0))
			x += i, y -= i, delta -= 2;
			if (delta <= 1) break;
		}
		cout << x << " " << y << endl;
	} else cout << n / 2 << " " << n / 2 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}