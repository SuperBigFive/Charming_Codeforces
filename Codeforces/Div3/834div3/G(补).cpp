#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> b (n + 1), pos (n + 1), front (n + 1);
	for (int i = 1; i <= (n >> 1); ++i) {
		cin >> b[i];
		pos[b[i]] = i;
	}
	priority_queue <int> pq;
	for (int i = n; i >= 1; --i) {
		if (pos[i]) pq.push (pos[i]);
		else {
			if (pq.empty ()) {
				cout << -1 << endl;
				return;
			}
			front[pq.top ()] = i;
			pq.pop ();
		}
	}
	for (int i = 1; i <= (n >> 1); ++i) {
		cout << front[i] << " " << b[i] << " \n"[i == (n >> 1)];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}