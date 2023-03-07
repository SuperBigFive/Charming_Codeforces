#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, k;

void init () {}

void charming () {
	init ();	
	cin >> n >> k;
	vector <int> ans;
	if (!k) {cout << -1 << endl; return;}
	if (n == 1 && k == n) {cout << 1 << endl; return;}
	if (k & 1) {
		ans.emplace_back (1);
		int cnt = 1;
		for (int i = 2; i <= n; i += 2) {
			if (cnt < k) {ans.emplace_back (i + 1), ans.emplace_back (i), cnt += 2;}
			else {ans.emplace_back (i), --i;}
		}
	}
	else {
		int cnt = 0;
		for (int i = 1; i <= n; i += 2) {
			if (cnt < k) {ans.emplace_back (i + 1), ans.emplace_back (i), cnt += 2;}
			else {ans.emplace_back (i), --i;}
		}
	}
	for (auto it : ans) cout << it << " \n"[it == ans.back ()];
}

signed main () {
	charming ();
	return 0;
}