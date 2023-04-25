#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n;

void init () {
	
}

void charming () {
	init ();
	cin >> n;
	int x, y;
	for (int i = 1; i <=  n; ++i) {
		cin >> x >> y;
	}
	printf ("%.15llf", (double) 1 / n);
}

signed main () {
	charming ();
	return 0;
}