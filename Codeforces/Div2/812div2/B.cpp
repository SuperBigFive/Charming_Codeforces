#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int val[maxn];

void init () {
	
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		if (val[i] < val[i - 1]) flag = true;
		if (flag && val[i] > val[i - 1]) {
			cout << "NO" << endl;
			return;
		} 
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}