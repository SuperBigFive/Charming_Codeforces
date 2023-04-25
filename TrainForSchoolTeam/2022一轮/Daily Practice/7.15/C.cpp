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
const int maxn = 1e5 + 5;

void charming () {
	ll a, b, c;
	cin >> a >> b >> c;
	if (a <= b + c) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		ll ans = 2 * b + 2 * c + 1;
		if (a == 1 && (!b) && (!c)) cout << 0 << endl;
		else cout << ans << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}