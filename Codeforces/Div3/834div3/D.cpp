#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	int need[10] = {10, 10, 5, 10, 5, 2, 5, 10, 5, 10};
	cin >> n >> m;
	int cur = n, k = 1, nxt;
	while (!(cur % 10)) cur /= 10;
	cur %= 10;
	while (true) {
		nxt = need[cur];
		if (k * nxt <= m) {
			k *= nxt;
			cur = n * k;
			while (!(cur % 10)) cur /= 10;
			cur %= 10;
		}
		else break;
	}
	k *= max (1ll, m / k);
	cout << n * k << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}