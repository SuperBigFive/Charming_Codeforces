#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {
	
}

void charming () {
	cin >> n;
	cout << (1 << n) - 1 << endl;
}

signed main () {
	cin >> t;
	while (t--)	charming ();
	return 0;
}