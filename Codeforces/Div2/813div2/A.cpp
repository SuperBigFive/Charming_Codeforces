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

int t, n, k;
int val[maxn];

void init () {
	
}

void charming () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	int res = 0;
	for (int i = 1; i <= k; ++i) {
		if (val[i] > k) ++res;
	}	
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}