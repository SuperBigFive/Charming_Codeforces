#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;
template <class T> void read (T & x){
    x = 0;
	int f = 1;
	char c = getchar ();
    while (c < '0' || c > '9') {
		if (c == '-') f = -1; 
		c = getchar ();
	}
    while (c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar ();
	}
    x *= f;
}

int n, l, r, tmp_l, tmp_r;
int arr[maxn];

void ask (int pos) {
	cout << "? " << pos << endl;
	fflush (stdout);
}

void answer (int pos) {
	cout << "! " << pos << endl;
	fflush (stdout);
}

void brute_force () {
	for (int i = 1; i <= n; ++i) {
		ask (i);
		cin >> arr[i];
	}
	arr[0] = arr[n + 1] = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]) {
			answer (i);
			break;
		}
	}
}

void charming () {
	cin >> n;
	if (n <= 100) {
		brute_force ();
		return;
	}
	l = 1, r = n;
	int val_l, val_r, val_tmpl, val_tmpr;
	ask (1), cin >> val_l;
	ask (2), cin >> val_tmpr;
	ask (n), cin >> val_r;
	ask (n - 1), cin >> val_tmpl;
	if (val_tmpr > val_l) {
		answer (1);
		return;
	}
	if (val_tmpl  > val_r) {
		answer (n);
		return;
	}
	l = 2, r = n - 1;
	int mid, val_tmp;
	while (l <= r) {
		mid = (l + r) / 2;
		ask (mid);
		cin >> val_tmp;
		ask (mid - 1);
		cin >> val_tmpl;
		ask (mid + 1);
		cin >> val_tmpr;
		if (val_tmp < min (val_tmpl, val_tmpr)) {
			answer (mid);
			return;
		}
		if (val_tmp < val_tmpr) r = mid;
		else l = mid + 1;
	}
	answer (l);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
} 
