#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 998244353;

int t, n, k;
int match[maxn], f[maxn], z[maxn];
char s[maxn];

void init () {
	for (int i = 0; i <= n; ++i) {
		match[i] = f[i] = z[i] = 0;
	}
}

void get_match () {
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max ((ll)0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  match[1] = n;
  for (int i = 2; i <= n; ++i) {
  	match[i] = z[i - 1];
	}
}

void charming () {
	init ();
	scanf ("%s", s);
	scanf ("%lld", &k);
	n = strlen (s);
	get_match ();
	for (int i = 1; i <= n; ++i) if (match[i]) {
		++f[(i << 1) - 2 + k];
		int tmp = ((i + match[i] - 1) - ((i << 1) - 2 + k)) / k + 1;
		tmp = (i << 1) - 2 + k + tmp * k;
		--f[tmp];
	}
	for (int i = 1; i <= n; ++i) {
		if (i - k >= 0) f[i] += f[i - k];
	}
	ll res = 1;
	for (int i = 1; i <= n; ++i) 
	res = (res * (f[i] + 1)) % mod;
	printf ("%lld\n", res);
}

signed main () {
	//freopen ("input.in", "r", stdin);
	scanf ("%lld", &t);
	while (t--) charming ();
	return 0;
}