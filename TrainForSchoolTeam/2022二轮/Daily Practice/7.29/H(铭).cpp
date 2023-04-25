#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 1e6 + 5;

int read () {
  int x = 0, f = 1;
	char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar ();
	}
	return x * f;
}

ll a, b, c, d;
ll value[1005][1005];

void init () {
	
}

void get_fun () {
	ll tmp;
	for (int i = 1; i <= 1000; ++i) {
		tmp = 0;
		for (int j = 1; j <= 1000; ++j) {
			if (__gcd (i, j) == 1 && i + j < 1000) ++tmp;
			value[i][j] = tmp + value[i - 1][j];
		}
	}
}


ll solve (int n, int m) {
	ll res = 0;
	int up_ = min (n, m);
	const int tt = 1000;
	int j, j1, j2, tmp1, tmp2;
	get_fun ();
	for (int i = 1; i <= up_; i = j + 1) {
		tmp1 = n / i;
		tmp2 = m / i;
		j1 = n / tmp1;
		j2 = m / tmp2;
		j = min (j1, j2);
		res += (j - i + 1) * value[min (n / i, tt)][min (m / i, tt)];// fun (n / i, m / i);
		//cout << res << ' ';
	}
	//cout << res << endl;
	return res;
}

void charming () {
	cin >> a >> b >> c >> d;
	int t = clock ();
	ll res = solve (b, d) - solve (a - 1, d) - solve (b, c - 1) + solve (a - 1, c - 1);
	//cout << solve (b, d) << ' ' << solve (a - 1 , d) << ' ' << solve (b, c - 1) << ' ' << solve (a - 1, c - 1) << endl;
	cout << res << endl;
	//cout << clock () - t << "ms" << endl;
}

signed main () {
	charming ();
	return 0;
}