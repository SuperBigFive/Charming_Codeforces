#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int n, tot;
int val[maxn], prime[maxn];
bool vis[maxn];
vi pos[maxn];

void init () {
	
}

void get_prime () {
	for (int i = 2; i < maxn; ++i) {
		if (!vis[i]) prime[++tot] = i;
		for (int j = 1; j <= tot && i * prime[j] < maxn; ++j) {
			vis[i * prime[j]] = true;
			if (!(i % prime[j])) break;
		}
	}
}

void charming () {
	scanf ("%lld",&n);
	for (int i = 1; i <= n; ++i) scanf ("%lld", &val[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= tot && prime[j] * prime[j] <= val[i]; ++j) {
			if (!(val[i] % prime[j])) {
				pos[prime[j]].emplace_back (i);
				while (!(val[i] % prime[j])) val[i] /= prime[j];
			}
		}
		if (val[i] > 1) pos[val[i]].emplace_back (i);
	}
	ll sum = n * (n + 1) / 2, res = 0;
	int l, r;
	for (int i = 1; i <= tot; ++i) {
		if (pos[prime[i]].size ()) {
			l = 1;
			res += sum;
			for (auto it : pos[prime[i]]) {
				r = it;
				res -= (r - l) * (r - l + 1) / 2;
				l = it + 1;
			}
			res -= (n - l + 1) * (n - l + 2) / 2;
		}
	}
	cout << res << endl;
}

signed main () {
	get_prime ();
	charming ();
	cout << prime[tot - 1] << endl;
	return 0;
}