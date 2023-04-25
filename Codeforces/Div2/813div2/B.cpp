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
int res[maxn];

void init () {

}

void charming () {
	init ();
	cin >> n;
	for (int i = n; i >= 1; i -= 2) {
		res[i] = i - 1;
		res[i - 1] = i;
	}
	if (!res[1]) res[1] = 1;
	for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}