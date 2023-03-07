#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;

ll l, r, x, y, k;

void charming () {
	cin >> l >> r >> x >> y >> k;
	for (int i = x; i <= y; ++i) {
		if (k * i >= l && k * i <= r) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main () {
	charming ();
	return 0;
}