#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define pd push_back
using namespace std;
const int maxn = 1e5 + 5;

ll t, n;

void charming () {
	cin >> n;
	ll i, j, tmp, ans = 0;
	i = 1;
	while (i <= n) {
		tmp = n / i;
		j = n / tmp;
		if (j > n) j = n;
		ans += (j - i + 1) * (n / i);
		i = j + 1;
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}