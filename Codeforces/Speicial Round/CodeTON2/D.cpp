#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pip pair <int, pii> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 3e5 + 5;

inl int read () {
	char ch = getchar ();
	bool flag = true;
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = false;
		ch = getchar();
	}
	int k = ch -'0';
	while (ch = getchar(), ch <= '9' && ch >= '0') {
		k = (k << 1) + (k << 3);
		k += (ch-'0');
	}
	if (flag) return k;
	return -k;
}

int t, n, m;
int l[maxn], r[maxn];
vector <ll> c[maxn];

void init () {
	for (int i = 0; i < n; ++i) {
		c[i].clear ();
		l[i] = r[i] = 0;
	}
}

void charming () {
	init ();
	scanf ("%lld%lld", &n, &m);
	ll val;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf ("%lld", &val);
			c[i].pb (val);
		}
	}
	ll tmp_val;
	for (int i = 0; i < m - 1; ++i) {
		tmp_val = c[0][i];
		for (int j = 1; j < n; ++j) {
			if (c[j][i] > tmp_val) {
				r[j] += c[j][i] - tmp_val;
				c[j][i + 1] += c[j][i] - tmp_val;
			}
			if (c[j][i] < tmp_val) {
				r[j] -= tmp_val - c[j][i];
				c[j][i + 1] -= tmp_val - c[j][i];
			}
		}
	}
	if (r[1] && r[2]) {
		printf ("1 %lld\n", abs (r[1]));
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (r[i]) {
			printf ("%lld %lld\n", i + 1, abs (r[i]));
			return;
		}
	}
}

signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	cin >> t;
	while (t--) charming ();
	return 0;
}