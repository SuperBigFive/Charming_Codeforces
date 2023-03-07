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
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;

int n;
int st[maxn];
ll fac[maxn], pow2[maxn], dp[maxn];
vi adj[maxn];

ll ex_gcd (ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	ll GCD = ex_gcd (b, a % b, x, y);
	ll tmp = y;
	y = x - (a / b) * y;
	x = tmp;
	return GCD;
}

bool liEu (ll a, ll b, ll c, ll &x,ll &y) {
	ex_gcd (a, b, x, y);
	x = (x % b + b) % b;
	return true;
} 

void get_fac () {
	fac[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
}

void get_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		pow2[i] = (pow2[i - 1] << 1) % mod;
	}
}

ll get_inv (ll num) {
	ll x, y;
	liEu (num, mod, 1, x, y);
	return x;
}

int dfs (int f, int now) {
	if (adj[now].size () == 1 && now != 1) {
		dp[now] = 1;
		return 1;
	}
	int num = 0;
	for (auto it : adj[now]) {
		if (it == f) continue;
		if (dfs (now, it)) ++num;
	}
	if (num & 1) st[now] = 0, ++num;
	else st[now] = 1;
	dp[now] = fac[num] * get_inv (pow2[num / 2] * fac[num / 2] % mod) % mod;
	return st[now];
}

void init () {
}

void charming () {
	init ();
	cin >> n;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}
	dfs (0, 1);
	ll ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = (ans * dp[i]) % mod;
	}
	cout << ans << endl;
}

signed main () {
	get_fac ();
	get_pow2 ();
	charming ();
	return 0;
}