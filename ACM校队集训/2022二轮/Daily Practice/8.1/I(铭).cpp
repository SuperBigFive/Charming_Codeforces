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
const int maxn = 1e6 + 5;

int t, p;
int res[maxn];

void init () {
	for (int i = 1; i <= p; ++i) res[i] = 0;
}

void charming () {
	init ();
	cin >> p;
	ll ans = 0;
	for (int i = 1; i < p; ++i) {
		int now = i, cnt = 1;
		while (now > 1) {
			if (res[p % now]) {
				cnt += res[p % now];
				break;
			}
			++cnt;
			now = p % now;
		}
		ans += cnt;
		res[i] = cnt;
	}
	printf ("%.10lf\n", (double) ans / (p - 1));
}

signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	cin >> t;
	//int ti = clock ();
	while (t--) charming ();
	//cout << clock () - ti << "ms" << endl;
	return 0;
}