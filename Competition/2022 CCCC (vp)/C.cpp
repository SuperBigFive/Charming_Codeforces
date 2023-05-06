#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int ban, tog, age1, age2;

void init () {}

void charming () {
	init ();
	cin >> ban >> tog >> age1 >> age2;
	if (max (age1, age2) < ban) {
		cout << age1 << "-N" << " " << age2 << "-N" << endl;
		cout << "zhang da zai lai ba" << endl;
	}
	else if (min (age1, age2) >= ban) {
		cout << age1 << "-Y" << " " << age2 << "-Y" << endl;
		cout << "huan ying ru guan" << endl;
	}
	else if (max (age1, age2) >= tog) {
		cout << age1 << "-Y" << " " << age2 << "-Y" << endl;
		if (age1 > age2) cout << "qing 1 zhao gu hao 2" << endl;
		else cout << "qing 2 zhao gu hao 1" << endl;
	}
	else if (age1 > age2) {
		cout << age1 << "-Y" << " " << age2 << "-N" << endl;
		cout << "1: huan ying ru guan" << endl;
	}
	else {
		cout << age1 << "-N" << " " << age2 << "-Y" << endl;
		cout << "2: huan ying ru guan" << endl;
	}
}

signed main () {
	charming ();
	return 0;
}