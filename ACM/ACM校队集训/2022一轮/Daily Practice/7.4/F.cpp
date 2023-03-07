#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int n, m, t;
int mmap[700][700];

void charming () {
	cin >> n >> m;
	bool ok = false;
	char ch;
	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			mmap[i][j] = ch;
			//cin >> mmap[i][j];
			if (mmap[i][j] == 'A') ok = true;
			else flag = true;
		}
	}
	if (!ok) {
		cout << "MORTAL" << endl;
		return;
	}
	if (!flag) {
		cout << 0 << endl;
		return;
	}
	if (n == 1) {
		if (mmap[1][1] == 'A' || mmap[1][m] == 'A') {
			cout << 1 << endl;
			return;
		}
		else {
			cout << 2 << endl;
			return;
		}
	}
	if (m == 1) {
		if (mmap[1][1] == 'A' || mmap[n][1] == 'A') {
			cout << 1 << endl;
			return;
		}
		else {
			cout << 2 << endl;
			return;
		}
	}
	ok = true;
	for (int j = 1; j <= m; ++j) {
		if (mmap[1][j] != 'A') ok = false;
	}
	if (ok) {
		cout << 1 << endl;
		return;
	}
	
	ok = true;
	for (int j = 1; j <= m; ++j) {
		if (mmap[n][j] != 'A') ok = false;
	}
	if (ok) {
		cout << 1 << endl;
		return;
	}
	
	ok = true;
	for (int j = 1; j <= n; ++j) {
		if (mmap[j][1] != 'A') ok = false;
	}
	if (ok) {
		cout << 1 << endl;
		return;
	}
	
	ok = true;
	for (int j = 1; j <= n; ++j) {
		if (mmap[j][m] != 'A') ok = false;
	}
	if (ok) {
		cout << 1 << endl;
		return;
	}
	
	if (mmap[1][1] == 'A' || mmap[1][m] == 'A' || mmap[n][1] == 'A' || mmap[n][m] == 'A') {
		cout << 2 << endl;
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		ok = true;
		for (int j = 1; j <= m; ++j) {
			if (mmap[i][j] != 'A') ok = false;
		}
		if (ok) {
			cout << 2 << endl;
			return;
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		ok = true;
		for (int j = 1; j <= n; ++j) {
			if (mmap[j][i] != 'A') ok = false;
		}
		if (ok) {
			cout << 2 << endl;
			return;
		}
	}
	
	ok = false;
	for (int i = 1; i <= n; ++i) {
		if (mmap[i][1] == 'A' || mmap[i][m] == 'A') ok = true; 
	}
	for (int i = 1; i <= m; ++i) {
		if (mmap[1][i] == 'A' || mmap[n][i] == 'A') ok = true;
	}
	if (ok) cout << 3 << endl;
	else cout << 4 << endl;
	return;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
} 
