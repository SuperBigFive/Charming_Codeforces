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

int n, m, r;
int s[maxn], b[maxn];
pii res = {-1, -1};

void init () {
	
}

void charming () {
	init ();
	cin >> n >> m >> r;
	ll mmin = INT_MAX, mmax = -1;
	for (int i = 1; i <= n; ++i) cin >> s[i], mmin = min (mmin, s[i]);
	for (int i = 1; i <= m; ++i) cin >> b[i], mmax = max (mmax, b[i]);
	int num = r / mmin;
	int ans;
	if (mmax > mmin) ans = num * mmax + r - num * mmin;
	else ans = r;
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}