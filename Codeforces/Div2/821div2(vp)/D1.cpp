#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, x, y;
string a, b;
vector <int> pos;

void init () {
	pos.clear ();
}

void charming () {
	init ();	
	cin >> n >> x >> y;
	cin >> a >> b;
	a = '#' + a, b = '#' + b;
	for (int i = 1; i <= n; ++i) 
	if (a[i] != b[i]) {
		pos.emplace_back (i);
	}
	if (pos.size () & 1) {
		cout << -1 << endl;
		return;
	}
	if (pos.size () == 2 && pos[0] + 1 == pos[1]) 
	cout << min (x, y * 2) << endl;
	else cout << (pos.size () / 2) * y << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}