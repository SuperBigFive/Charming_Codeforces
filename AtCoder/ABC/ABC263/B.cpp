#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 2e5 + 5;

int n, res;
int pre[maxn];

void find (int x) {
	++res;
	if (pre[x] == x) return;
	find (pre[x]);
}

void init () {
	
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		pre[i] = i;
	}
	for (int i = 2; i <= n; ++i) {
		cin >> pre[i];
	}
	find (n);
	cout << res - 1 << endl;
}

signed main () {
	charming ();
	return 0;
}