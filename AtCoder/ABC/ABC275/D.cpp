#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;

int n;
map <int, int> ans;

void init () {}

int dfs (int u) {
	if (ans.count (u)) return ans[u];
	if (!u) return ans[u] = 1;
	return ans[u] = dfs (u / 2) + dfs (u / 3);
}

void charming () {
	init ();
	cin >> n;
	cout << dfs (n) << endl;
}

signed main () {
	charming ();
	return 0;
}