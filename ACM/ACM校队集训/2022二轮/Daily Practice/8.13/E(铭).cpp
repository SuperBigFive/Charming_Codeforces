#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 5;

int t, n;
int val[maxn], pow2[maxn];
ll sum[maxn];
vi comp;

void init () {
	comp.clear ();
}

void get_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i <= 32; ++i) {
		pow2[i] = pow2[i - 1] * 2;
	}
}

ll get_GCD_s (int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (!(num % i)) return num / i;
	}
	return 1;
}

void charming () {
	init ();
	cin >> n;
	int lim = -1;
	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		sum[i] = sum[i - 1] + val[i];
		lim = max (val[i], lim);
		if (i <= 32) {
			if (pow2[i - 1] < val[i]) {
				flag = true;
			}
		}
	}
	if (flag) {
		cout << -1 << endl;
		return;
	}
	if (!lim) {
		cout << 1 << endl;
		return;
	}
	int b_now, b_old, num;
	for (int i = 1; i <= n; ++i) {
		b_now = sum[i] - sum[i - 1];
		b_old = sum[i - 1]; 
		num = 1 - (b_now - b_old);
		if (num) comp.emplace_back (abs (num));
	}
	ll GCD = 0, GCD_s;
	for (auto it : comp) {
		if (!GCD) GCD = it;
		else GCD = __gcd (GCD, it);
	}
	if (!GCD) {
		cout << -1 << endl;
		return;
	}
	GCD_s = get_GCD_s (GCD);
	if (GCD > lim && GCD_s <= lim) cout << GCD << endl;
	else cout << -1 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	get_pow2 ();
	cin >> t;
	while (t--) charming ();
	return 0;
}