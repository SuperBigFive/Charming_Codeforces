#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n;
ll a[maxn];

void init () {
	
}

void charming () {
	init ();
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", &a[i]);
	}
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	int p1 = 1, p2 = 2;
	ll ans = 0;
	while (p1 <= n && p2 <= n) {
		if (a[p2] > a[p2 - 1]) ans += a[p2], ++p2;
		else ans += a[p2 - 1], p1 = p2, ++p2;
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}