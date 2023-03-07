#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e2 + 5;

int t, n;
int mmap[maxn][maxn], mmap2[maxn][maxn], mmap3[maxn][maxn], mmap4[maxn][maxn];

void init () {
}

void charming () {
	init ();
	cin >> n;
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> ch;
			mmap[i][j] = ch - '0';
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			mmap2[i][j] = mmap[n - j + 1][i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			mmap3[i][j] = mmap2[n - j + 1][i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			mmap4[i][j] = mmap3[n - j + 1][i];
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int zero = 0, one = 0;
			if (mmap[i][j]) ++one;
			else ++zero;
			if (mmap2[i][j]) ++one;
			else ++zero;
			if (mmap3[i][j]) ++one;
			else ++zero;
			if (mmap4[i][j]) ++one;
			else ++zero;
			ans += min (one, zero);
		}
	}
	cout << ans / 4 << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}