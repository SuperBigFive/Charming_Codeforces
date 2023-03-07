#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;

int t;
ll n;
void charming () {
	cin >> n;
	if (n > 1) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}