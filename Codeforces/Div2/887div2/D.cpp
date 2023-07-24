#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <pair <int, int> > a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
	sort (a.begin () + 1, a.begin () + 1 + n, [] (pair <int, int> &x,
	pair <int, int> &y) {return x.first > y.first;});
	vector <int> ans (n + 5);
	for (int i = 1, last = n, j = n, k = n, delta; i <= j; ++i) {
		delta = last - a[i].first;
		last = a[i].first;
		if (delta > 0) {
			ans[a[i].second] = k - 1;
			for (int p = 1; p <= delta; ++p) {
				if (a[j].first != i - 1) return void (cout << "NO" << endl);
				ans[a[j--].second] = -k;
			}
			--k;
		}
		else ans[a[i].second] = k;
		--k;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) 
	cout << ans[i] << " ";
	cout << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}