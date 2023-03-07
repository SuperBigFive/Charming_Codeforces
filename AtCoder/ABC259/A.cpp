#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 2e6 + 5;

void init () {}

void charming () {
	init ();
	int n, m, x, t, d;
	cin >> n >> m >> x >> t >> d;
	if (m > x) cout << t << endl;
	else cout << (t + (m - x) * d) << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
