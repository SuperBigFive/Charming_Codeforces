#include <bits/stdc++.h>
#define ll long long
#define run(bgin, end) for (int i = begin; i <= end; ++i)
using namespace std;
const int mod = 7;
const ll mod2 = pow (2, 32);

int s, depth;
ll a0, ans;
bool flag;

void init () {flag = false, ans = 0;}

void get_a (ll a, ll &a11, ll &a22) {
	a11 = ((213346089*a) % mod2 + 870413) % mod2;
	a22 = ((166042049*a) % mod2 + 598777) % mod2;
}

bool check (int now_d, int now_s, int up_d) {
	if (now_s + (up_d - now_d)*6 < s) return false;
	return true;
}

void IDDFS (ll now_a, int now_d, int now_s, int up_d) {
	if (flag || now_d > up_d) return;
	if (now_s >= s) {
		ans = up_d;
		flag = true;
		return;
	}
	ll a1, a2;
	if (check (now_d, now_s, up_d)) {
		get_a (now_a, a1, a2);
		IDDFS (a1, now_d + 1, now_s + a1 % mod, up_d);
		IDDFS (a2, now_d + 1, now_s + a2 % mod, up_d);
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	init ();
	cin >> a0 >> s;
	depth = (s - 1)/6 + 1;
	while (!flag) IDDFS(a0, 1, a0 % mod, depth), ++depth;
	cout << ans << endl;
}
