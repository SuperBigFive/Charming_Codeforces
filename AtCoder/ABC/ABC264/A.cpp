#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int l, r;
char str[8] = {"atcoder"};

void init () {
	
}

void charming () {
	cin >> l >> r;
	for (int i = l; i <= r; ++i) {
		cout << str[i - 1];
	}
	cout << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}