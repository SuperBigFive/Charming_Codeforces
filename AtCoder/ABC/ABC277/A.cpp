#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, x;
int p[maxn];

void init () {}

void charming () {
	init ();
	cin >> n >> x;
	int id;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		if (p[i] == x) id = i;
	}
	cout << id << endl;
}

signed main () {
	charming ();
	return 0;
}