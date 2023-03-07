#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

ll t, n, c, q;
char s1[maxn], s2[maxn];
void init () {
	
}
void charming () {
	init ();
	cin >> n;
	cin >> s1 + 1;
	cin >> s2 + 1;
	int cnt1 = 0, cnt2 = 0;
	vector <pii> lr1, lr2;
	for (int i = 1; i <= n; ++i) {
		if (s1[i] == '1') {
			int j = i;
			while (s1[j] == '1' && j <= n) ++j;
			lr1.pb ({i, j - 1});
			++cnt1;
			i = j - 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (s2[i] == '1') {
			int j = i;
			while (s2[j] == '1' && j <= n) ++j;
			lr2.pb ({i, j - 1});
			++cnt2;
			i = j - 1;
		}
	}
	if (cnt1 != cnt2 || (s1[1] != s2[1]) || (s1[n] != s2[n])) {
		cout << -1 << endl;
		return;
	}
	ll ans = 0;
	for (int i = 0; i < cnt1; ++i) {
		ans += abs (lr1[i].fir - lr2[i].fir) + abs (lr1[i].se - lr2[i].se);
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}