#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e2 + 5;

int t, n;
int arr[maxn];
int dp[maxn][maxn];

void init () {}

void charming () {
	cin >> n;
	int odd = 0, even = 0;
	for (int i = 1, var; i <= n; ++i) {
		cin >> var;
		if (var & 1) ++odd;
		else ++even;
	}
	cout << ((odd % 4 == 3 || odd % 4 == 0 
	|| (odd % 4 == 1 && (even & 1))) ? "Alice" : "Bob" ) << endl; 
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}