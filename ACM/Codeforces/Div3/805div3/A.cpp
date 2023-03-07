#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 1e5 + 5;

int t, n;

void charming () {
	cin >> n;
	ll tmp = 10;
	while (tmp <= n) tmp *= 10;
	tmp /= 10;
	cout << n - tmp << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}