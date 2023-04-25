#include <bits/stdc++.h>
#include <random>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define ppii pair <int, pii >
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 998244353;


int n, q, tot;
ll seed;
int m[maxn], ans[maxn];
int lim[11][401][401];

ll binpow (ll num, ll pow, ll mod) {
	ll res = 1;
	while (pow) {
		if (pow & 1) res = (res * num) % mod;
		pow >>= 1;
		num = (num * num) % mod;
	}
	return res;
}

ll get_res () {
	ll res = 0;
	for (int i = 1; i <= q; ++i) {
		res = (res +  ans[i] * binpow (seed, q - i, mod) % mod) % mod;
	}
	return res;
}

void init () {
	
}

ll solve (int iq, int eq, int aq) {
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (lim[i][iq][eq] <= aq && lim[i][iq][eq] != -1) ++res;
	}
	ans[++tot] = res;
	return res;
}

void charming () {
	cin >> n >> q;
	int iq, eq, aq;
	memset (lim, -1, sizeof lim);
	for (int i = 1; i <= n; ++i) {
		cin >> m[i];
		for (int j = 1; j <= m[i]; ++j){
			cin >> iq >> eq >> aq;
			if (lim[i][iq][eq] != -1 && lim[i][iq][eq] < aq) continue;
			lim[i][iq][eq] = aq;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 400; ++j) {
			int mmin = INT_MAX;
			for (int k = 1; k <= 400; ++k) {
				if (lim[i][j][k] != -1) {
					mmin = min (mmin, lim[i][j][k]);
				}
				if (lim[i][j - 1][k] != -1) {
					mmin = min (mmin, lim[i][j - 1][k]);
				}
				if (mmin != INT_MAX) {
					lim[i][j][k] = mmin;
				}
			}
		}
	}
	
	cin >> seed;
	std::mt19937 rng (seed);
	std::uniform_int_distribution<> u(1,400);
	int lastans = 0;
	for (int i = 1;i <= q; ++i)
	{
	    int IQ = (u(rng) ^ lastans) % 400 + 1;  // The IQ of the i-th friend
	    int EQ = (u(rng) ^ lastans) % 400 + 1;  // The EQ of the i-th friend
	    int AQ = (u(rng) ^ lastans) % 400 + 1;  // The AQ of the i-th friend
	    lastans = solve (IQ, EQ, AQ);  // The answer to the i-th friend
	}
	cout << get_res () << endl;
}

signed main () {
	charming ();
	return 0;
}