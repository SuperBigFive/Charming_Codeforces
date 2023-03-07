#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
int i, j, k;
int mmax, mmin;
int arr[maxn];
char str[maxn];

void init () {
	mmax = -1, mmin = INT_MAX;
	
}

bool check () {}

void solve () {
	cin >> n;
	cin >> str;
	int ans = 0;
	int len = strlen (str);
	if (len % 2) {
		ans += 1;
		int idx = len/2;
		while (str[idx-1] == str[idx]) -- idx, ans += 2;
		cout << ans << endl;
	}
	else {
		ans += 2;
		int idx = len/2 - 1;
		while (str[idx-1] == str[idx]) --idx, ans += 2;
		cout << ans << endl;
	}
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) solve ();
}
