#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, x, y;

void init () {}

void charming () {
	init ();
	cin >> x >> y;
	string s;
	cin >> s;
	int cntr = 0, cntl = 0, cntu = 0, cntd = 0;
	for (auto &it : s) {
		if (it == 'R') ++cntr;
		else if (it == 'L') ++cntl;
		else if (it == 'U') ++cntu;
		else ++cntd;
	}
	if ((x == 0 && y == 0) || (cntr - cntl == x 
	&& cntu - cntd == y)) {cout << "Impossible";}
	else if (cntr + cntl == 0 && ((x == 0 && y > 0 && cntu - cntd >= y)
	|| (x == 0 && y < 0 && cntu - cntd <= y))) {cout << "Impossible";}
	else if (cntu + cntd == 0 && ((x > 0 && y == 0 && cntr - cntl >= x)
	|| (x < 0 && y == 0 && cntr - cntl <= x))) {cout << "Impossible";}
	else if (x == cntr - cntl) {
		if (x == 0) {
			if (cntr) {cout << "R", --cntr;}
			else if (cntl) {cout << "L", --cntl;}
			else {
				if (y > 0) {
					while (cntd > 0) {cout << "D", --cntd;}
					while (cntu > 0) {cout << "U", --cntu;}
				}
				else {
					while (cntu > 0) {cout << "U", --cntu;}
					while (cntd > 0) {cout << "D", --cntd;}
				}
			}
		}
		while (cntu > 0) {cout << "U", --cntu;}
		while (cntd > 0) {cout << "D", --cntd;}
		while (cntr > 0) {cout << "R", --cntr;}
		while (cntl > 0) {cout << "L", --cntl;}
	}
	else if (y == cntu - cntd) {
	 	if (y == 0) {
	 		if (cntu) {cout << "U", --cntu;}
	 		else if (cntd) {cout << "D", --cntd;}
	 		else {
	 			if (x > 0) {
	 				while (cntl > 0) {cout << "L", --cntl;}
	 				while (cntr > 0) {cout << "R", --cntr;}
	 			}
	 			else {
	 				while (cntr > 0) {cout << "R", --cntr;}
	 				while (cntl > 0) {cout << "L", --cntl;}
	 			}
	 		}
	 	}
		while (cntr > 0) {cout << "R", --cntr;}
		while (cntl > 0) {cout << "L", --cntl;}
		while (cntd > 0) {cout << "D", --cntd;}
		while (cntu > 0) {cout << "U", --cntu;}
	}
	else {
		if (y == 0) {
			if (cntu) {cout << "U", --cntu;}
			else if (cntd) {cout << "D", --cntd;}
			else {
	 			if (x > 0) {
	 				while (cntl > 0) {cout << "L", --cntl;}
	 				while (cntr > 0) {cout << "R", --cntr;}
	 			}
	 			else {
	 				while (cntr > 0) {cout << "R", --cntr;}
	 				while (cntl > 0) {cout << "L", --cntl;}
	 			}
	 		}
		}
		while (cntr > 0) {cout << "R", --cntr;}
		while (cntl > 0) {cout << "L", --cntl;}
		while (cntu > 0) {cout << "U", --cntu;}
		while (cntd > 0) {cout << "D", --cntd;}
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}