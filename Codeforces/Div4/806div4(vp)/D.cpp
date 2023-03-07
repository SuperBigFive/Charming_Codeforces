#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int t, n, k;
char str[maxn][9];

void init () {
	
}

void charming () {
	init ();
	cin >> n;
	map <ll, bool> exist;
	for (int i = 1; i <= n; ++i) {
		cin >> str[i] + 1;
	}
	for (int i = 1; i <= n; ++i) {
		ll val = 0, len = strlen (str[i] + 1);
		for (int j = 1; j <= len; ++j) {
			val = val * 26 + str[i][j] - 'a' + 1;
		}
		exist[val] = true;
	}
	exist[0] = true;
	for (int i = 1; i <= n; ++i) {
		ll len = strlen (str[i] + 1);
		bool ok = false;
		for (int j = 1; j < len; ++j) {
			ll tmp1 = 0, tmp2 = 0;
			for (int k = 1; k <= j; ++k) {
				tmp1 = tmp1 * 26 + str[i][k] - 'a' + 1;
			}
			for (int k = j + 1; k <= len; ++k) {
				tmp2 = tmp2 * 26 + str[i][k] - 'a' + 1;
			}
			if (exist[tmp1] && exist[tmp2]) {
				cout << 1;
				ok = true;
				break;
			}
		}
		if (!ok) cout << 0;
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