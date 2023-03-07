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

int t, n, x;

void init () {
	
}

void charming () {
	cin >> x;
	int key[4];
	cin >> key[1] >> key[2] >> key[3];
	if (!key[x]) {
		cout << "NO" << endl;
		return;
	}
	if (!key[key[x]]) {
		cout << "NO" << endl;;
		return;
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}