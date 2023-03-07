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
const int maxn = 2e5 + 5;

int t, n;

void charming () {
	cin >> n;
	vi res;
	for (int i = 9; i >= 1 && n; --i) {
		if (n >= i) {
			res.pb (i);
			n -= i;
		}
		else {
			res.pb (n);
			break;
		}
	}
	for (int i = res.size () - 1; i >= 0; --i) {
		cout << res[i];
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}