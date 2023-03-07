#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
vector <int> h;

void init () {}

bool check (int tim) {
	int one = tim, two = tim;
	vector <int> cpy = h;
	for (auto &it : cpy) {
		if (two <= 0) {
			two = 0;
			break;
		}
		else {
			int k = it / 2;
			it -= min (two, k) * 2;
			two -= k;
		}
	}
	int remain = 0;
	one += two;
	for (auto it : cpy) remain += it;
	return remain <= one;
}

void charming () {
	init ();
	cin >> n;
	h.resize (n);
	for (auto &it : h) cin >> it;
	int l = 1, r = INT_MAX, res = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) r = mid - 1, res = mid;
		else l = mid + 1;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}