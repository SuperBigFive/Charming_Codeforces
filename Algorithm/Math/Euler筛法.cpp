#include <iostream>
#include <cstring>
#include <cmath>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n, cnt;
ll ans = 1;
int prime[maxn];
ll f[maxn];
bool vis[maxn];

void init () {
	ans = 1;
}

void Euler_sieve (int num) {
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) prime[++cnt] = i, f[i] = 2, ans += f[i];
		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
			vis[i * prime[j]] = true;
			if (!(i % prime[j])) {
				break;	
			}
		}
	}
}

void charming () {
	init ();
	cin >> n;
	Euler_sieve (n);
	ll ans = 0;
	cout << 1 << ' ';
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			cout << i << ' ';
			++ans;
		}
	}
	cout << endl << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
