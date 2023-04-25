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

int t, n, mmax;
ll pow3[maxn];

void get_pow3 () {
	pow3[0] = 1;
	for (int i = 1; i <= 20; ++i) {
		pow3[i] = pow3[i - 1] * 3;
		if (pow3[i] > 1e9) {
			mmax = i - 1;
			break;
		}
	}
}

void init () {
	
}

void charming () {
	cin >> n;
	if (n > mmax + 1) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << pow3[i - 1] << ' ';
	}
	cout << endl;
}

signed main () {
	get_pow3 ();
	cin >> t;
	while (t--)	charming ();
	return 0;
}