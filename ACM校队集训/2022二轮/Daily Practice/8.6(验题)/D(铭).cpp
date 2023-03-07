#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register <int>
using namespace std;
const int maxn = 2e5 + 5;

int t, e, l, r, b;

void init () {
	
}

void charming () {
	init ();
	cin >> e >> l >> r >> b;
	ll mmax = l + r, mmin = e;
	if (l > r) swap (l, r); 
	if (e >= b - 1) mmax += e + b;
	else {
		mmax += 2 * e + 1;
	}
	mmin += r;
	if (!r && b) mmin += 1;
	cout << mmin << ' ' << mmax << endl;

}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}