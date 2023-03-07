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
char s[maxn];

void init () {
	
}
void charming () {
	init ();
	cin >> n >> c >> q;
	cin >> s + 1;
	ll l, r;
	vector <ll> cnt;
	vector <pair <ll, ll> > lr;
	ll tot = 0;
	for (int i = 1; i <= c; ++i) {
		cin >> l >> r;
		lr.pb ({l, r});
		if (!tot) cnt.pb (n + r - l + 1);
		else cnt.pb (r - l + 1 + cnt[tot - 1]);
		++tot;
	}
	ll k;
	ll id, id2;
	for (int i = 1; i <= q; ++i) {
		cin >> k;
		id = -1, id2 = -1;
		while (k > n) {
			id = lower_bound (cnt.begin (), cnt.end (), k) - cnt.begin ();
			if (id == 0) {
				cout << s[lr[0].fir + k - n - 1] << endl;
				break;
			}
			id2 = k - cnt[id - 1] - 1;
			k = lr[id].fir + id2;
		}
		if (id) cout << s[k] << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}