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

int n, m, s, t;
ll a[maxn], go_right[maxn], go_left[maxn];

void init () {
	
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; ++i) {
		go_right[i] = go_right[i - 1];
		if (a[i] < a[i - 1]) go_right[i] += a[i - 1] - a[i];
	}
	for (int i = n - 1; i >= 1; --i) {
		go_left[i] = go_left[i + 1];
		if (a[i] < a[i + 1]) go_left[i] += a[i + 1] - a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> s >> t;
		if (s < t) cout << go_right[t] - go_right[s] << endl;
		else cout << go_left[t] - go_left[s] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}