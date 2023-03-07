#include <bits/stdc++.h>
#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
ll arr[maxn];

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	bool ok = true;
	for (int i = 2; i <= n; ++i) {
		if (arr[i] % arr[1]) {
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