#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn = 2e5 + 5;

int t;
ull p, a, b, c;

void init () {
	
}

void charming () {
	init ();
	cin >> p >> a >> b >> c;
	//ll mmin = LONG_MAX;
	ull cost1, cost2, cost3;
	if (!(p % a) || !(p % b) || !(p % c)) {
		cout << 0 << endl;
		return;
	}
	cost1 = a * (p / a + 1) - p;
	cost2 = b * (p / b + 1) - p;
	cost3 = c * (p / c + 1) - p;
	ull ans = min (cost1, min (cost2, cost3));
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--)	charming ();
	return 0;
}
