#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <pair <int, int> > monster (n);
	multiset <int> power;
	for (int i = 0; i < n; ++i) cin >> monster[i].first;
	for (int i = 0; i < n; ++i) {
		cin >> monster[i].second;
		power.insert (monster[i].second);
	}
	sort (monster.begin (), monster.end ());
	int cur = 0, p = 0, wp;
	while (p < n) {
		if (cur >= monster[p].first) {
			auto it = power.find (monster[p].second);
			power.erase (it);
			++p;			
			continue;
		}
		if (k <= 0) {
			cout << "NO" << endl;
			return;
		}
		wp = *(power.lower_bound (-1));
		if (cur > 0) k -= wp;
		int d = k / wp;
		if (cur + (d + 1) * (k + k - d * wp) / 2 
		< monster[p].first) {
			cout << "NO" << endl;
			return;
		}
		int l = 0, r = d, res = d;
		while (l <= r) {
			int mid = l + r >> 1;
			if (cur + (mid + 1) * (k + k - mid * wp) / 2
			>= monster[p].first) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		//cout << *power.find (monster[p].second) << endl;
		cur += (res + 1) * (k + k - res * wp) / 2;
		k -= wp * res;
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}