#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e4 + 5;

int t, n;
int a[maxn], b[maxn], c[maxn];
int dis[maxn];

void init () {
	for (int i = 1; i <= n; ++i) dis[maxn] = 0;
} 

void charming () {
	cin >> n;
	bool ok = false; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1;i <= n; ++i) {
		cin >> b[i];
		dis[i] = a[i] - b[i];
		if (dis[i] < 0) ok = true;
	}
	if (ok) {
		cout << "NO" << endl;
		return;
	}
	bool change = false;
	int mmax = 0;
	for (int i = 1; i <= n; ++i) 
		dis[i] = abs(dis[i]), mmax = max (mmax, dis[i]);
	for (int i = 1; i <= n; ++i) {
		if (dis[i] != mmax && b[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
