#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int> 
#define pip pait <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 2e5 + 5;

int p;
int vis[maxn];

void init () {
}

void charming () {
	cin >> p;
	int cnt = p;
	int i, j;
	for (i = 0; cnt; ++i) {
		j = i;
		while (true) {
			if (j - i > p) break;
			if (!vis[(i * i + j * j) % p]) --cnt;
			vis[(i * i + j * j) % p] = i + 1;
			++j;
		}
	}
	cout << i - 1 << endl;
}

signed main () {
	charming ();
	/*for (int i = 1; i <= 200; ++i) {
		cout << ((i * i + 1) % 13) << ' ';
	}*/
	/*for (int i = 0; i <= 100; ++i) {
		for (int j = i; j <= 100; ++j) {
			if ((i * i + j * j) % 35 == 21) {
				cout << i << ' ' << j << ' ' << i * i + j * j << endl;
			}
		}
	}*/
	return 0;
}