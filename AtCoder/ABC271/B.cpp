#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
vector <int> arr[maxn];

void init () {}

void charming () {
	cin >> n >> m;
	for (int i = 1, siz; i <= n; ++i) {
		cin >> siz;
		arr[i].emplace_back (siz);
		for (int j = 1, var; j <= siz; ++j) {
			cin >> var;
			arr[i].emplace_back (var);
		}
	}
	for (int i = 1, s, t; i <= m; ++i) {
		cin >> s >> t;
		cout << arr[s][t] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}