#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 1e3 + 5;

int read () {
  int x = 0, f = 1;
	char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar ();
	}
	return x * f;
}

int n, m;
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
char mp1[maxn][maxn], mp2[maxn][maxn], mp3[maxn][maxn];

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mp1[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mp3[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp1[i][j] == '.') mp2[i][j] = 'X';
			else mp2[i][j] = '.';
		}
	}
	int common = 0, uncommon = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp3[i][j] == mp1[i][j]) ++common;
			else ++uncommon;
		}
	}
	int change = min (common, uncommon);
	if (change > (n * m / 2)) {
		cout << -1 << endl;
		return;
	}
	if (common > uncommon) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << mp1[i][j];
			}
			cout << endl;
		}
	}
	else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << mp2[i][j];
			}
			cout << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
} 