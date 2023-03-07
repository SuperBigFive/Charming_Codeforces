#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

int ask (int i, int j) {
	cout << "? " << i << " " << j << endl;
	fflush (stdout);
	int tmp;
	cin >> tmp;
	return tmp;
}

void ans (int x, int y) {
	cout << "! " << x << " " << y << endl;;
	fflush (stdout);
	int tmp;
	cin >> tmp;
}

void charming () {
	init ();
	cin >> n;
	if (n <= 2) {
		ans (1, 2);
		return;
	}
	array <int, 3> a;
	vector <int> b;
	for (int i = 1; i <= n; ++i) 
	b.emplace_back (i);
	while (b.size () > 2) {
		for (int i = 0; i < 3; ++i)
		a[i] = b.back (), b.pop_back ();
		int chk1 = ask (a[0], a[1]);
		int chk2 = ask (a[0], a[2]);
		if (chk1 != chk2) b.emplace_back (a[0]);
		if (chk1 >= chk2) b.emplace_back (a[1]);
		if (chk1 <= chk2) b.emplace_back (a[2]);
	}
	ans (b[0], b[1]);
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}