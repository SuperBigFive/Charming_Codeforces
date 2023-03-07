#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int n, k;

void init () {
	
}

void charming () {
	cin >> n >> k;
	if (!n) cout << "Austin" << endl;
	else {
		if (k == 1) {
			if (n & 1) cout << "Adrien" << endl;
			else cout << "Austin" << endl;
		}
		else cout << "Adrien" << endl;
	}
}

signed main () {
	charming ();
	return 0;
}