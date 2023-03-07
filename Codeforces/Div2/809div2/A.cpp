#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
int arr[maxn];
char str[maxn];

void init () {
	for (int i = 1; i <= m; ++i) str[i] = 'B';
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	map <int, bool> vis;
	for (int i = 1; i <= n; ++i) {
		int mmin = min (arr[i], m + 1 - arr[i]);
		if (!vis[mmin])vis[mmin] = true;
		else vis[max (arr[i], m + 1 - arr[i])] = true;
	}
	for (int i = 1; i <= m; ++i) {
		if (vis[i]) str[i] = 'A';
		else str[i] = 'B';
	}
	for (int i = 1; i <= m; ++i) {
		printf ("%c", str[i]);
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}