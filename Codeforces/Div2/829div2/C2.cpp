#include <bits/stdc++.h>
#define ll long long
#define itn ll
using namespace std;
const int maxn = 4e5 + 5;

int t, n;
int a[maxn], st[maxn];

void init () {
	fill (st, st + n + 5, 0);
}

void charming () {
	init ();
	cin >> n;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == 1) ++cnt1;
		else if (a[i] == -1) ++cnt2;
	}
	vector <pair <int, int> > seg;
	int delta = abs (cnt1 - cnt2);
	int key = cnt1 > cnt2 ? 1 : -1;
	if (delta & 1) {
		cout << -1 << endl;
		return;
	}
	for (int i = n, last = n + 2; i > 1 && delta > 0; --i) {
		if (a[i] == key && i != last - 1) {
			delta -= 2;
			st[i] = true;
			last = i;
		}
	}
	if (delta > 0) {
		cout << -1 << endl;
		return;
	}
	for (int i = n; i >= 1; --i) {
		if (st[i]) seg.emplace_back (i - 1, i), --i;
		else seg.emplace_back (i, i);
	}
	sort (seg.begin (), seg.end ());
	cout << seg.size () << endl;
	for (auto [l, r] : seg) cout << l << " " << r << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}