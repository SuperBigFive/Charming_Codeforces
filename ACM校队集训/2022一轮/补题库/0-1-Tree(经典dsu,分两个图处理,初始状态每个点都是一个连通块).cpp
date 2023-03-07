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
const int maxn = 2e5 + 5;

int n;
ll pre[2][maxn], siz[2][maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		pre[0][i] = pre[1][i] = i;
		siz[0][i] = siz[1][i] = 1;
	}
}

ll find (int x, int c) {
	if (x == pre[c][x]) return x;
	return pre[c][x] = find (pre[c][x], c);
}

void joint (int x, int y, int c) {
	int fx = find (x, c), fy = find (y, c);
	if (siz[c][fx] < siz[c][fy]) swap (fx, fy);
	pre[c][fy] = fx;
	siz[c][fx] += siz[c][fy];
}

void charming () {
	cin >> n;
	init ();
	int uu, vv, cc;
	for (int i = 1; i < n; ++i) {
		cin >> uu >> vv >> cc;
		joint (uu, vv, cc);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (find (i, 0) == i) ans += siz[0][i] * (siz[0][i] - 1);
		if (find (i, 1) == i) ans += siz[1][i] * (siz[1][i] - 1);
		ans += (siz[0][find (i, 0)] - 1) * (siz[1][find (i, 1)] - 1);
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}