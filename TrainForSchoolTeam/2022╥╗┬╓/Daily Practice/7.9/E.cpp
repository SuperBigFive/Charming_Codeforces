#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 2e3+ 5;

int t, n, m;

void scan (int x, int y) {
	cout << "SCAN " << x << " " << y << endl;
	fflush (stdout);
}

void dig (int x, int y) {
	cout << "DIG " << x << " " << y << endl;
	fflush (stdout);
}

void charming () {
	cin >> n >> m;
	if (n * m < 7) {
		int tmp;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				dig (i, j), cin >> tmp;
				if (tmp == 1) ++cnt;
				if (cnt == 2) return;
			}
		}
	}
	int sum_r1r2, sum_c1c2, diff_r1r2, diff_c1c2;
	int tmp1, tmp2;
	scan (1, 1), cin >> tmp1;
	scan (n, 1), cin >> tmp2;
	tmp1 += 4;
	tmp2 += 2 - 2 * n;
	sum_r1r2 = (tmp1 - tmp2) / 2;
	sum_c1c2 = (tmp1 + tmp2) / 2;
	scan (sum_r1r2 / 2, 1), cin >> tmp1;
	scan (1, sum_c1c2 / 2), cin >> tmp2;
	diff_r1r2 = tmp1 + 2 - sum_c1c2;
	diff_c1c2 = tmp2 + 2 - sum_r1r2;
	int r1, c1, r2, c2;
	r1 = (sum_r1r2 + diff_r1r2) / 2;
	r2 = sum_r1r2 - r1;
	c1 = (sum_c1c2 + diff_c1c2) / 2;
	c2 = sum_c1c2 - c1;
	dig (r1, c1), cin >> tmp1;
	if (tmp1 != 1) {
		dig (r1, c2), cin >> tmp1;
		dig (r2, c1), cin >> tmp2;
	}
	else dig (r2, c2), cin >> tmp2;
}

int main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
