#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;

int n, q;
char str[maxn];

void charming () {
	cin >> n >> q;
	int opt, x;
	cin >> str + 1;
	int del = 0;
	for (int i = 1; i <= q; ++i) {
		cin >> opt >> x;
		if (opt == 1) del = (del + x) % n;
		else {
			if (x >= del + 1) {
				cout << str[x - del] << endl;
			}
			else {
				cout << str[n - del + x] << endl;
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
