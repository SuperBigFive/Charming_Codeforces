#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int q, n;
int cnts[30], cntt[30];
int cnt[30][30];
char s[maxn], t[maxn];

void init () {
	memset (cnts, 0, sizeof cnts);
	memset (cntt, 0, sizeof cntt);
	memset (cnt, 0, sizeof cnt);
}

void charming () {
	init ();
	cin >> n;
	cin >> s + 1 >> t + 1;
	reverse (t + 1, t + 1 + n);
	for (int i = 1; i <= n; ++i) 
	++cnts[s[i] - 'a'], ++cntt[t[i] - 'a'];
	for (int i = 0; i < 26; ++i) {
		if ((cnts[i] + cntt[i]) & 1) {
			cout << "NO" << endl;
			return;
		}
	}
	for (int i = 1; i <= n; ++i) ++cnt[s[i] - 'a'][t[i] - 'a'];
	bool flag = n & 1 ? true : false;
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (i == j && (cnt[i][j] & 1)) {
				if (!flag) {
					cout << "NO" << endl;
					return;
				}
				else flag = false;
			}
			if ((cnt[i][j] + cnt[j][i]) & 1) {
				if (!flag) {
					cout << "NO" << endl;
					return;
				}
				else flag = false;
			}
		}
	}
	cout << "YES" << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> q;
	while (q--) charming ();
	return 0;
}