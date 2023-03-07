#include <bits/stdc++.h>
#define ll long long 
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
char str[maxn];

void charming () {
	cin >> n;
	cin >> str + 1;
	int p1 = 1, p2 = n;
	if (str[1] == 'A' && str[n] == 'B') {
		cout << "No" << endl;
		return;
	}
	if (n == 2 && str[1] == 'B' && str[2] == 'A') {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	return;
}

signed main () {
	charming ();
	return 0;
}