#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n;
int arr[maxn];
int mx_front[maxn], mx_back[maxn];

void init () {}

void win (int st) {
	if (st) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	exit (0);
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	for (int i = 1, j; i <= n; i = j) {
		j = i + 1;
		while (j <= n && arr[j] > arr[j - 1]) ++j;
		for (int k = i; k < j; ++k) mx_front[k] = j - k;
	}
	for (int i = n, j; i >= 1; i = j) {
		j = i - 1;
		while (j >= 1 && arr[j] > arr[j + 1]) --j;
		for (int k = i; k > j; --k) mx_back[k] = k - j;
	}
	int l = 1, r = n, now = 1, last = 0;
	while (true) {
		if (arr[r] <= last || arr[l] <= last || l > r) win (now ^ 1);
		if (arr[l] == arr[r]) {
			if ((mx_front[l] & 1) || (mx_back[r] & 1)) win (now);
			else win (now ^ 1);
		}
		else if (arr[l] > arr[r]) {
			if ((mx_front[l] & 1)) win (now);
			else last = arr[r--];
		}
		else if (arr[l] < arr[r]) {
			if ((mx_back[r] & 1)) win (now);
			else last = arr[l++];
		}
		now ^= 1;
	}		
}

signed main () {
	charming ();
	return 0;
}