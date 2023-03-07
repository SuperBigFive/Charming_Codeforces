#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;
const int lim = 1000000000;
const int mx = 1000000000000000000;

int powten[20];

void init () {}

int ask (int k1, int k2) {
	cout << "? " << k1 << ' ' << k2 << endl;
	fflush (stdout);
	int tmp;
	cin >> tmp;
	return tmp;
}

void ans (int k) {
	cout << "! " << k << endl;
	fflush (stdout);
}

void charming () {
	powten[0] = 1;
	for (int i = 1; i <= 18; ++i) {
		powten[i] = powten[i - 1] * 10;
	}
	int l = 3, r = mx, res = 3, tmp;
	for (int i = 17; i >= 1; --i) {
		tmp = ask (1, powten[i]);
		if (tmp == -1) continue;
		l = max (powten[i], tmp + 1);
		res = l - 1;
		r = powten[i + 1]; 
		break;
	}
	if (l == 3) r = 10;
	mt19937 rnd (random_device {} ());
	if (r < lim) {
		while (l <= r) {
			int mid = l + r >> 1;
			tmp = ask (1, mid);
			if (tmp == -1) r = mid - 1;
			else l = max (mid, tmp + 1) + 1, res = l - 1;
		}
	}
	else {
		while (true) {
			int r1 = rnd () % l + 1, r2 = rnd () % l + 1;
			int tmp1 = ask (r1, r2), tmp2 = ask (r2, r1);
			if (tmp1 == tmp2) continue;
			res = tmp1 + tmp2;
			break;
		}
	}
	ans (res);
}

signed main () {
	charming ();
	return 0;
}