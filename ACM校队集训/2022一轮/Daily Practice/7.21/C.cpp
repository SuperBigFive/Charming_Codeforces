#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define ppii pair <int, pii >
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int cnt0[maxn], cnt1[maxn];
char s[maxn], t[maxn];
pii lr[maxn];

void init () {
	
}

void charming () {
	cin >> s + 1;
	cin >> t + 1;
	int lens = strlen (s + 1), lent = strlen (t + 1);
	for (int i = 1; i <= lens; ++i) {
		cnt0[i] = cnt0[i - 1];
		cnt1[i] = cnt1[i - 1];
		if (s[i] == '0') ++cnt0[i];
		else ++cnt1[i];
	}
	for (int i = 1; i <= lent; ++i) {
		if (i <= lens) {
			lr[i] = {max ((ll)1, i - (lent - lens)), i};
		}
		else {
			lr[i] = {max ((ll)1, lens - (lent - i)), lens};
		}
	}
	ll ans = 0;
	for (int i = 1; i <= lent; ++i) {
		if (t[i] == '1') {
			ans += cnt0[lr[i].se] - cnt0[lr[i].fir - 1];
		}
		else ans += cnt1[lr[i].se] - cnt1[lr[i].fir - 1];
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}