#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
map <int, int> pre;

void init () {}

int find (int x) {
	if (x == pre[x]) return x;
	return pre[x] = find (pre[x]);
}

void charming () {
	init ();
	cin >> n;
	pre[1] = 1;
	for (int i = 1, a, b, fa, fb; i <= n; ++i) {
		cin >> a >> b;
		if (!pre.count (a)) pre[a] = a;
		if (!pre.count (b)) pre[b] = b;
		fa = find (a), fb = find (b);
		if (fa != fb) pre[fa] = fb;
	}
	ll mx = 1;
	for (auto it : pre) {
		if (find (it.first) == find (1)) 
		mx = max (mx, it.first);
	}
	cout << mx << endl;
}

signed main () {
	charming ();
	return 0;
}