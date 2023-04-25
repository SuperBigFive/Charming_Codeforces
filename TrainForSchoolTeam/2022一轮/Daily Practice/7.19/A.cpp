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

int n, x, y, m;
int k[maxn], p[maxn];

void init () {
	
}

void charming () {
	init ();
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> p[i];
	}
	
	if (x < y && m >= x) {
		cout << "Right" << endl;
		return;
	}
	if (x > y && m > n - x) {
		cout << "Right" << endl;
		return;
	}
	
	int sign = x < y ? 1 : -1;
	for (int i = 1; i <= m; ++i) {
		if (p[i] != k[x + sign * i]) {
			cout << "Wrong" << endl;
			return;
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		if (k[x - i] != k[x + i]) {
			cout << "Right" << endl;
			return;
		}
	}
	cout << "Unsure" << endl;
}

signed main () {
	charming ();
	return 0;
}