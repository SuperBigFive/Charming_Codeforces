#include <bits/stdc++.h>
#define ll long long
#define int ll 
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, tot;
int fac[maxn];
map <ll, int> old;

void init () {
	tot = 0;
	old.clear ();
}

ll get_hash (int a, int b) {
	return a * 1e9 + b;
}

int dfs (int a, int b) {
	if (old[get_hash (a, b)]) return old[get_hash (a, b)];
	if (b == a + 1) return a - 1;
	if (a == 1) return 0;
	int diff = b - a, res = a - 1, add;
	for (int i = 1; i <= tot; ++i) {
		if (!(diff % fac[i])) {
			add = a % fac[i]; 
			res = min ({res, fac[i] - add + 1 + dfs (a / fac[i] + 1, b / fac[i] + 1), 
			add + 1 + dfs (a / fac[i], b / fac[i])});
		}
	}
	return old[get_hash (a, b)] = res;
}

void charming () {
	init ();
	int a, b;
	scanf ("%lld%lld", &a, &b);
	if (a > b) swap (a, b);
	int d = b - a;
	for (int i = 2; i * i <= d; ++i) {
		if (!(d % i)) {
			fac[++tot] = i;
			while (!(d % i)) d /= i;
		}
	}
	if(d > 1) fac[++tot] = d;
	printf ("%lld\n", dfs (a, b));
}

signed main () {
	scanf ("%lld", &t);
	while (t--) charming ();
	return 0;
}