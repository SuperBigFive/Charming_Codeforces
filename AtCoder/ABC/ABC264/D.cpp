#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int l, r;
char str[8];
char atcoder[8] = {"atcoder"};

void charming () {
	cin >> str;
	int res = 0;
	for (int i = 0; i <= 6; ++i) {
		for (int j = 0; j <= 6; ++j) {
			if (str[j] == atcoder[i]) {
				int k = j;
				while (k > i) {
					++res;
					swap (str[k], str[k - 1]);
					--k;
				}
			}
		}
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}