#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

struct Node {
	int val;
	int pos;
}b[maxn];
int t, n, k;
int a[maxn], c[maxn];

bool cmp (Node x, Node y) {
	return x.val < y.val;
}

void charming () {
	cin >> n >> k;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		c[i] = a[i];
		b[i].pos = i;
		b[i].val = a[i] % k;
	}
	sort (b + 1, b + 1 + n, cmp);
	for (int i = 1; i <= n; ++i) {
		a[i] = c[b[i].pos];
	}
	int p1 = 1, p2 = n;
	ll ans = 0;
	while (p1 <= p2) {
		if (((a[p1] + a[p1+1]) % k) < ((a[p1] + a[p2]) % k)) {
			ans += (a[p1] + a[p1+1]) / k;
			p1 += 2;
		}
		else {
			ans += (a[p1] + a[p2]) / k;
			++p1, --p2;
		}
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
