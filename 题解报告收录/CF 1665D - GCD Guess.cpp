#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t;

int ask (int a, int b) {
	cout << "? " << a << " " << b << endl;
	fflush (stdout);
	int tmp;
	cin >> tmp;
	return tmp;
}

void ans (int x) {
	cout << "! " << x << endl;
	fflush (stdout);
}

void charming () {
	int r = 0;
	for (int i = 1, tmp; i <= 30; ++i) {
		tmp = ask (-r + (1 << (i - 1)), -r + (1 << (i - 1)) + (1 << i));
		if (tmp == (1 << i)) r += 1 << (i - 1);
	}
	ans (r);
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}