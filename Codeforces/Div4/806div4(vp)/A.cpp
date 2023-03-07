#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int t, n, k;
char str[maxn];
bool vis[maxn];

void init () {
	memset (vis, false, sizeof vis);
}

void charming () {
	init ();
	char ch1, ch2, ch3;
	cin >> ch1 >> ch2 >> ch3;
	if (ch1 != 'Y' && ch1 != 'y') {
		cout << "NO" << endl;
		return;
	}
	if (ch2 != 'E' && ch2 != 'e') {
		cout << "NO" << endl;
		return;
	}
	if (ch3 != 'S' && ch3 != 's') {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}