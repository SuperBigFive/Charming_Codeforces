#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
char str[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	cin >> str + 1;
	int res = 0, cnt0 = 0, cnt1 = 0;
	for (int i = 1, j; i <= n; i = j) {
		if (str[i] == '0') ++cnt0, j = i + 1;
		else {
			j = i;
			while (str[j] == '1' && j <= n) ++j;
			if (j > n || !cnt0) continue; 
			cnt1 += min ((ll)2, j - i);
		}
	}
	if (!cnt0) cout << 0 << endl;
	else {
		res = 2 * (cnt0 - 1) - cnt1;
		cout << res << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}