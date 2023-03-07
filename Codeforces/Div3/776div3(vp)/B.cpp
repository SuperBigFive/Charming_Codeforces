#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

int t, l, r, a;

void charming () {
	cin >> l >> r >> a;
	if (a == 1) cout << r << endl;
	else if (r < a) cout << (r / a + r % a) << endl;
	else {
		ll b = a * ((r - 1) / a + 1) - 1;
		if (r >= b && l <= b) {
			cout << (b / a + b % a) << endl;
			return;
		}
		if (r < b) {
			if (l <= b - a) {
				cout << (b - a) / a + (b - a) % a << endl;
				return;
			}
			cout << r / a + r % a << endl;
			return;
		}
		if (l > b) {
			cout << r / a + r % a << endl;
			return;
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
}
