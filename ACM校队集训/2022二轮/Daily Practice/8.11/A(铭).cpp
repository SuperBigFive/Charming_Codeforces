#include <bits/stdc++.h>
#define ll long long
#define int ll 
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n, a, b;

void charming () {
	cin >> n >> a >> b;
	int dis1, dis2, dis3, dis4, dis, st;
	dis1 = abs (a - 1) + abs (b - 1);	
	dis2 = abs (a - 1) + abs (b - n);
	dis3 = abs (a - n) + abs (b - 1);
	dis4 = abs (a - n) + abs (b - n);
	dis = min (dis1, min (dis2, min (dis3, dis4)));
	if (dis1 == dis) st = 1;
	else if (dis2 == dis) st = 2;
	else if (dis3 == dis) st = 3;
	else st = 4;
	if (st == 1) {
		for (int i = 1; i < n; ++i) cout << 'L';
		for (int i = 1; i < n; ++i) cout << 'U';
		for (int i = 1; i < b; ++i) cout << 'R';
		for (int i = 1; i < a; ++i) cout << 'D';
	}
	else if (st == 2) {
		for (int i = 1; i < n; ++i) cout << 'U';
		for (int i = 1; i < n; ++i) cout << 'R';
		for (int i = 1; i < a; ++i) cout << 'D';
		for (int i = n; i > b; --i) cout << 'L';
	}
	else if (st == 3) {
		for (int i = 1; i < n; ++i) cout << 'L';
		for (int i = 1; i < n; ++i) cout << 'D';
		for (int i = 1; i < b; ++i) cout << 'R';
		for (int i = n; i > a; --i) cout << 'U';
	}
	else if (st == 4) {
		for (int i = 1; i < n; ++i) cout << 'D';
		for (int i = 1; i < n; ++i) cout << 'R';
		for (int i = n; i > a; --i) cout << 'U';
		for (int i = n; i > b; --i) cout << 'L';
	}
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}