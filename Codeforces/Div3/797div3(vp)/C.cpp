#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int s[maxn], f[maxn], d[maxn];

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) cin >> f[i];
	for (int i = 1; i <= n; ++i) {
		cout << f[i] - max (f[i-1], s[i]) << " ";
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
