#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll 
#define ld long double
#define inl inline
using namespace std;
const int maxn = 1e2 + 5;

ll t, n, tot;
ll pow2[maxn];

void init () {
	
}

void build () {
	pow2[0] = 1;
	tot = 0;
	while (pow2[tot] < 1e9) {
		pow2[tot + 1] = pow2[tot] << 1;
		++tot;
	}
}

void charming () {
	init ();
	cin >> n;
	ll num2 = 0, num3 = 0;
	while (!(n % 3)) ++num3, n /= 3;
	while (!(n % 2)) ++num2, n >>= 1;
	if (num2 > num3 || n > 1) {
		cout << -1 << endl;
		return;
	}
	cout << num2 + (num3 - num2) * 2 << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	build ();
	cin >> t;
	while (t--) charming ();
	return 0;
}