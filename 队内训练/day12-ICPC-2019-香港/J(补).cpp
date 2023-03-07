#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 5e3 + 5;
const int M = 65;
const int mod = 1e9 + 7;

int t, m;
int a[N], POW10[N];
int dp[N][M][M][2];

void get (int n) {
	POW10[0] = 1;
	for (int i = 1; i <= n; ++i)
	POW10[i] = (POW10[i - 1] * 10) % m;
}

void init () {}

int dfs (int pos, int sum, int delta, int lim) {
	if (pos == 0) return delta == 0;
	if (dp[pos][sum][delta][lim] != -1) return dp[pos][sum][delta][lim];
	int mx = lim ? a[pos] : 9;
	ll res = 0;
	int nsum, ndelta, nlim;
	for (int i = 0; i <= mx; ++i) {
		nsum = (sum + i) % m, ndelta = (delta + (i * sum) - i * POW10[pos - 1]) % m;
		ndelta = ((ndelta % m) + m) % m, nlim = lim && (i == a[pos]);
		res = (res + dfs (pos - 1, nsum, ndelta, nlim)) % mod;
	}
	res = ((res + mod) % mod) + mod;
	return dp[pos][sum][delta][lim] = res;
}

int solve (string num) {
	int len = num.size ();
	get (len);
	num = '#' + num;
	for (int i = 1; i <= len; ++i)
	for (int j = 0; j < m; ++j)
	for (int k = 0; k < m; ++k)
	dp[i][j][k][0] = dp[i][j][k][1] = -1;
	for (int i = 1; i <= len; ++i)
	a[i] = num[i] - '0';
	return dfs (len, 0, 0, 1);
}

bool check (string num) {
	int sum = 0, f = 0, x = 0;
	int len = num.size ();
	num = '#' + num;
	for (int i = len; i >= 1; --i) {
		f = (f + (sum * (num[i] - '0'))) % m;;
		sum = (sum + (num[i] - '0')) % m;
		x = (x + POW10[i - 1] * (num[i] - '0')) % m;
	}
	return f % m == x % m;
}

void charming () {
	init ();
	string l, r;
	cin >> l >> r >> m;
	reverse (l.begin (), l.end ()), reverse (r.begin (), r.end ());
	ll res = solve (r) - solve (l) + check (l);
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}