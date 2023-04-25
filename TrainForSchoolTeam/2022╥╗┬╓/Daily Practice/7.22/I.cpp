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
int t[maxn];
map <int, bool> mark;

void init () {
	
}

void charming () {
	cin >> n;
	mark[0] = true;
	ll ans = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		if (mark[t[i]]) {
			mark[t[i]] = false;
		}
		else ++ans;
		mark[i] = true;
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}