#include <bits/stdc++.h>
#define ll long long
#define itn ll
using namespace std;
const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;

int t, n, x;
int a[maxn], cnt[maxn];
ll need[maxn];

void init () {

}

void get_pow () {
	
}

void get_need () {
	need[x] = 1;
	for (int i = x - 1; i >= 1; --i) {
		need[i] = need[i + 1] * (i + 1);
		if (need[i] > maxn) need[i] = maxn + 1;
	}
}

void charming () {
	init ();
	cin >> n >> x;
	get_pow ();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	get_need ();
	for (int i = 1; i < x; ++i) {
		if (!cnt[i]) continue;
		else if (!(cnt[i] % (i + 1))) {
			cnt[i + 1] += cnt[i] / (i + 1);
		}
		else {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

signed main () {
	charming ();
	return 0;
}