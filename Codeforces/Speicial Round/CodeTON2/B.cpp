#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pip pair <int, pii> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 1e6 + 5;

inl int read () {
	char ch = getchar ();
	bool flag = true;
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = false;
		ch = getchar();
	}
	int k = ch -'0';
	while (ch = getchar(), ch <= '9' && ch >= '0') {
		k = (k << 1) + (k << 3);
		k += (ch-'0');
	}
	if (flag) return k;
	return -k;
}

int t, n, x;
int val[maxn];

void charming () {
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	int up_, down_;
	up_ = val[1] + x, down_ = max ((ll)1, val[1] - x);
	ll res = 0;
	int now_up, now_down;
	for (int i = 2; i <= n; ++i) {
		now_up = val[i] + x;
		now_down = max ((ll)1, val[i] - x);
		if (now_down > up_ || now_up < down_) {
			++res;
			up_ = now_up;
			down_ = now_down;
			continue;
		}
		up_ = min (up_, now_up);
		down_ = max (down_, now_down);
	}
	cout << res << endl;
}

signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	cin >> t;
	while (t--) charming ();
	return 0;
}