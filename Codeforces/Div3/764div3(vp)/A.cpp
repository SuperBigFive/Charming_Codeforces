#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

int t, n;

void charming () {
	cin >> n;
	int mmax = -1, mmin = INT_MAX;
	int tmp;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		mmax = max (mmax, tmp);
		mmin = min (mmin, tmp);
	}
	cout << mmax - mmin << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--)
		charming ();
	return 0;
}
