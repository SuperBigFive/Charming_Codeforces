#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, a, b;
int bel[N];
array <int, 4> ans[N];

void init () {}

void charming () {
	init ();
	ans[1][0] = 1;
	int p = 2, step = 2;
	for (int i = 0; p < N; ++i) {
		if (!((i / 2) & 1)) {
			for (int j = p; j <= min (N - 1, p + step - 1); ++j) {
				bel[j] = 1;
			}
		}
		p += step, ++step;
	}
	for (int i = 2, c; i < N; ++i) {
		c = (i - 1) & 1;
		ans[i] = ans[i - 1];
		if (bel[i]) ++ans[i][2 + c];
		else ++ans[i][c];
	}
}

signed main () {
	charming ();
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 4; ++i)
		cout << ans[n][i] << " \n"[i == 3];
	}
	return 0;
}