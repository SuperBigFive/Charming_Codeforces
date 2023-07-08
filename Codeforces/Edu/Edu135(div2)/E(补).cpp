#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int n, m;
int ans[maxn], diff[maxn];
pair <int, int> pep[maxn];

void init () {
	fill (ans, ans + maxn, 0);
}

int ex_gcd (int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int GCD = ex_gcd (b, a % b, x, y);
	ll tmp = y;
	y = x - (a / b) * y;
	x = tmp;
	return GCD;
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> pep[i].first >> pep[i].second;
		ans[0] += pep[i].second;
		diff[i] = pep[i].first - pep[i].second;
	}
	sort (diff + 1, diff + 1 + n, [] (int &a, int &b) {
		return a > b;
	});
	for (int i = 1; i <= n; ++i) {
		ans[i] = ans[i - 1] + diff[i];
	}
	int a, b, x, y;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		int GCD = ex_gcd (a, b, x, y);
		if (n % GCD) {
			cout << -1 << endl;
			continue;
		}
		int c = n / GCD, k = a * b / GCD;
		x *= c, y *= c;
		int red = ((x * a % k) + k) % k;
		if (red > n) {
			cout << -1 << endl;
			continue;
		}
		int l = 0, r = ((n - red) / k), id = 0;
		while (l <= r) {
			int midl = l + (r - l) / 3;
			int midr = r - (r - l) / 3;
			if (ans[red + midl * k] > ans[red + midr * k]) r = midr - 1, id = midl;
			else l = midl + 1, id = midr;
		}
		cout << ans[red + id * k] << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}