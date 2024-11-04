#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 6e5 + 5;
const int MOD = 998244353;

int n, q;

void init () {}

void charming () {
	init ();
	cin >> q;
	int head = 1, tail = 0, ans = 1;
	vector <int> pow10 (N), s (N);
	pow10[0] = 1, s[1] = 1, tail = 1;
	for (int i = 1; i < N; ++i) pow10[i] = (pow10[i - 1] * 10) % MOD;
	for (int i = 1, opt, x; i <= q; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> x;
			s[++tail] = x;
			ans = (ans * 10 + x) % MOD;
		}
		else if (opt == 2) {
			ans = (ans - s[head++] * pow10[tail - head + 1]) % MOD;
		}
		else {
			ans = ((ans % MOD) + MOD) % MOD;
			cout << ans << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}