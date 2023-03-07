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
	ll ans = 0;
	char ch;
	for (int i = 1; i <= n * 7; ++i) {
		ch = getchar ();
		if (ch == '-') ++ans;
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}