#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
#define format pair <int, pair <int, int > >
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int tone1[21], tone2[21];
char str1[21][maxn], str2[21][maxn];

void init () {
	
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> str1[i] + 1;
	for (int i = 1; i <= n; ++i) cin >> str2[i] + 1;
	int len;
	for (int i = 1; i <= n; ++i) {
		len = strlen (str1[i] + 1);
		tone1[i] = str1[i][len] - '0';
	}
	for (int i = 1; i <= n; ++i) {
		len = strlen (str2[i] + 1);
		tone2[i] = str2[i][len] - '0';
	}
	if (tone1[n] < 3 || tone2[n] > 2) {
		cout << "NO" << endl;
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (tone1[i] < 3 && tone2[i] < 3) {
			cout << "NO" << endl;
			return;
		} 
		if (tone1[i] > 2 && tone2[i] > 2) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}