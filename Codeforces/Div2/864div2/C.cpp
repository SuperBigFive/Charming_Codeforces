#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

int ask (int ar, int ac) {
	cout << "? " << ar << " " << ac << endl;
	cout.flush ();
	int tmp;
	cin >> tmp;
	return tmp;	
}

void answer (int ar, int ac) {
	cout << "! " << ar << " " << ac << endl;	
	cout.flush ();
}

bool check (int x, int y, int dis) {
	return max (n - x + 1, m - y + 1) == dis;
}

void charming () {
	init ();
	cin >> n >> m;
	int dis1 = ask (1, 1);
	if (1 + dis1 <= n && 1 + dis1 <= m) {
		int dis2 = ask (1 + dis1, 1 + dis1);
		if (dis2 == 0) answer (1 + dis1, 1 + dis1);
		else {
			int dis3 = ask (1 + dis1, 1 + dis1 - dis2);
			if (dis3 == 0) answer (1 + dis1, 1 + dis1 - dis2);
			else answer (1 + dis1 - dis2, 1 + dis1);
		}
	}
	else if (1 + dis1 <= n) {
		int dis2 = ask (1 + dis1, 1);
		answer (1 + dis1, 1 + dis2);
	}
	else {
		int dis2 = ask (1, 1 + dis1);
		answer (1 + dis2, 1 + dis1);
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}