#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int maxn = 1e2 + 5;
const int maxm = 5e3 + 55;

int t, s;
int a[maxn], b[maxn];
int fa[maxn][maxn][maxm];
int fb[maxn][maxn][maxm];

void init () {memset (fa, 0, sizeof fa); memset (fb, 0, sizeof fb);}

void charming () {
	init ();
	cin >> s;
	int w, suma = 0, sumb = 0, sum = 0, cnta = 0, cntb = 0;
	for (int i = 1; i <= s; ++i) {
		cin >> w;
		sum -= w * i;
		if (w > 1) continue;
		a[++cnta] = i;
		suma += i;
	}
	for (int i = 1; i <= s; ++i) {
		cin >> w;
		sum += w * i;
		if (w > 2) continue;
		b[++cntb] = i;
		sumb += i;
	}
	if (!sum) {
		cout << 0 << endl;
		return;
	}
	if (sum < 0) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < maxn; ++i) 
	fa[i][0][0] = fb[i][0][0] = 1;
	for (int i = 1; i <= cnta; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 0; k <= suma; ++k) {
				fa[i][j][k] = fa[i - 1][j][k];
				if (k >= a[i]) fa[i][j][k] |= fa[i - 1][j - 1][k - a[i]];
			}
		}
	}
	for (int i = 1; i <= cntb; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 0; k <= sumb; ++k) {
				fb[i][j][k] = fb[i - 1][j][k];
				if (k >= b[i]) fb[i][j][k] |= fb[i - 1][j - 1][k - b[i]];
			}
		}
	}
	for (int i = 1; i <= min (cnta, cntb); ++i) {
		for (int j = 0; j <= min (sum, suma); ++j) {
			if (sum - j > sumb) continue;
			if (fa[cnta][i][j] && fb[cntb][i][sum - j]) {
				cout << i << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
			