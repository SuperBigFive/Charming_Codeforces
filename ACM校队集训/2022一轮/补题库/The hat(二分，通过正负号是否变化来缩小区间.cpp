#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int n;

void ask (int pos) {
	cout << "? " << pos << endl;
	fflush (stdout);
}

void ans (int pos) {
	cout << "! " << pos << endl;
	fflush (stdout); 
}

void charming () {
	cin >> n;
	if (n % 4) {
		ans (-1);
		return;
	}
	int l = 1, r = 1 + n / 2;
	int val_l, val_r, val_1, val_2;
	ask (l), cin >> val_l;
	ask (l + n / 2), cin >> val_r; 
	while (l < r) {
		int mid = (l + r) / 2;
		ask (mid), cin >> val_1;
		ask (mid + n / 2), cin >> val_2;
		if (val_1 == val_2) {
			ans (mid);
			return;
		}
		if ((val_1 - val_2) * (val_l - val_r) > 0) l = mid + 1;
		else r = mid;
	}
	ask (l), cin >> val_l;
	ask (r), cin >> val_r;
	if (val_l == val_r) ans (l);
	else ans (-1);
}

int main () {
	charming ();
	return 0; 
} 
