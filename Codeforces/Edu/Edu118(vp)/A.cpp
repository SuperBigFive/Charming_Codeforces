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

int t, x1, p1, x2, p2;

void init () {
	
}

void charming () {
	cin >> x1 >> p1 >> x2 >> p2;
	bool ok = false;
	if (p1 > p2) {
		swap (x1, x2);
		swap (p1, p2);
		ok = true;
	}
	p2 -= p1, p1 = 0;
	while (p2 > 0) {
		x2 *= 10;
		--p2;
		if (x1 < x2) {
			if (!ok) cout << "<" << endl;
			else cout << ">" << endl;
			return;
		}
	}
	if (x1 == x2) cout << "=" << endl;
	else if ((x1 > x2 && !ok) || (x1 < x2 && ok)) cout << ">" << endl;
	else cout << "<" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}