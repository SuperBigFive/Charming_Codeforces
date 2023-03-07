#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	priority_queue <int> pq;
	int res = 0;
	for (int i = 0, card; i < n; ++i) {
		cin >> card;
		if (card == 0 && pq.size ()) res += pq.top (), pq.pop ();
		else if (card > 0) pq.push (card);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}