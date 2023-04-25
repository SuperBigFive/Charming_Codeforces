#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define ppii pair <int, pii >
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
bool exist[7][maxn];

void init () {
	
}

void dfs (int digit, int now, int res) {
	if (now > digit) {
		exist[digit][res % n] = true;
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		dfs (digit, now + 1, (res * 10 + i) % n);
	}
}

void get_m () {
	for (int i = 1; i <= 6; ++i) {
		dfs (i, 1, 0);
	}
}

void charming () {
	cin >> n;
	//memset (exist, 0, sizeof exist);
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	
	ll res = 0, A = 0;
	bool ok = false;
	for (int i = 1; i <= n; ++i) {
		int j = 1;
		for (; j <= 6; ++j) {
			A = A * 10 % n;
			if (i - A < 0 && exist[j][i - A + n]) break;
			if (i - A >= 0 && exist[j][(i - A) % n]) break;
		}
		if (j > 6) {
			ok = true;
			break;
		}
		res += j;
		A = i;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}