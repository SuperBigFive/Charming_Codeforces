#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e3 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> m >> n;
	vector <vector <int> > rat (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i) cin >> rat[i][0];
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> rat[j][i];
		}
	}
	sort (rat.begin () + 1, rat.begin () + 1 + n, [] (vector <int> &x,
	vector <int> &y) {return x[1] < y[1];});
	vector <bitset <N> > bs (n + 5);
	for (int i = 1; i <= n; ++i) bs[i].set ();
	vector <vector <int> > pos (n + 5);
	for (int i = 1; i <= m; ++i) {
		bitset <N> remain;
		for (int j = 1; j <= n; ++j) 
		pos[rat[j][i]].emplace_back (j);
		for (int j = 1; j <= n; ++j) {
			for (auto x : pos[j]) bs[x] &= remain;
			for (auto x : pos[j]) remain.set (x);
			pos[j].clear ();
		}
	}
	
	vector <int> dp (n + 5);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (bs[i].test (j)) dp[i] = max (dp[i], dp[j]);
		}
		dp[i] += rat[i][0];
	}
	int ans = *max_element (dp.begin (), dp.end ());
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}