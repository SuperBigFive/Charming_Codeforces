#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;
char ch[2] = {'X', '.'};

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <string> A (n + 5), B (n + 5);
	for (int i = 1; i <= n; ++i) cin >> A[i], A[i] = '#' + A[i];
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> B[i], B[i] = '#' + B[i];
		for (int j = 1; j <= m; ++j) {
			if (B[i][j] == A[i][j]) ++cnt;
		}
	}
	int rev = (n * m - cnt > (n * m) / 2);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) 
		cout << ch[(A[i][j] == '.') ^ rev];
		cout << endl;
	}
}

signed main () {
	charming ();
	return 0;
}