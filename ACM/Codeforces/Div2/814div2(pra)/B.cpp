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

int t, n;
int val[maxn];

void init () {
	
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	ll max1 = -1, max2 = -1;
	int id_mx, id_mn;
	ll min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		if (val[i] > max1) {
			max1 = val[i];
			id_mx = i;
		}
		if (val[i] < min1) {
			min1 = val[i];
			id_mn = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (i != id_mx) max2 = max (max2, val[i]);
		if (i != id_mn) min2 = min (min2, val[i]);
	}
	ll res = max1 + max2 - min1 - min2;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}