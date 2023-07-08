#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;

int t, a, b, k;
vector <int> prim;

void get_prim () {
	for (int i = 2; i <= N; ++i) {
		bool ok = true;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				ok = false;
				break;
			}
		}
		if (ok) prim.emplace_back (i);
	}
}

void init () {}

void charming () {
	init ();
	cin >> a >> b >> k;
	if (a > b) swap (a, b);
	if (k == 1) {
		if (a == b || (b % a))cout << "NO" << endl;
		else cout << "YES" << endl;
		return;
	}
	int cnt = 0;
	for (auto &it : prim) {
		while (a % it == 0) {
			a /= it, ++cnt;
		}
		while (b % it == 0) {
			b /= it, ++cnt;
		}
	}
	cnt += (a > 1) + (b > 1);
	cout << (cnt >= k ? "YES" : "NO") << endl;
}

signed main () {
	get_prim ();
	cin >> t;
	while (t--) charming ();
	return 0;
}