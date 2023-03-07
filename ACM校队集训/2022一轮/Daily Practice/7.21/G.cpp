#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define ppii pair <int, pii >
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 1e5 + 5;

int n, k;
int a[maxn], tmp[maxn];

void ask (int num) {
	printf ("? %lld\n", num);
	fflush (stdout);
}

void ans (int num) {
	printf ("! %lld\n", num);
	fflush (stdout);
	exit (0);
}

void binary (int l, int r, int up_) {
	int cnt = 0;
	int mid, val;
	while (l <= r && cnt < up_) {
		mid = (l + r) / 2;
		ask (mid);
		scanf ("%lld", &val);
		++cnt;
		if (val == k) ans (mid);
		else if (val > k) r = mid - 1;
		else l = mid + 1;
	}
}

void charming () {
	scanf ("%lld%lld", &n, &k);
	int tot = 0, q, val;
	for (int i = 1; i <= n; ++i) a[i] = k;
	bool ok = true;
	ask (1);
	cin >> q;
	while (ok) {
		q = (tot * tot + 1) % n + 1;
		ask (q);
		++tot;
		scanf ("%lld", &val);
		if (val != k) ok = false;
	}
	int l, r;
	if (val < k) {
		l = q, r = q + tot;
		if (r > n) {
			binary (l, n, (1000 - tot) / 2);
			binary (1, r - n, (1000 - tot) / 2);
		}
		else binary (l, r, 1000 - tot);
	}
	else {
		r = q;
		l = q - tot;
		if (l < 1) {
			binary (1, r, (1000 - tot) / 2);
			binary (n + l, n, (1000 - tot) / 2);
		}
		else binary (l, r, 1000 - tot);
	}
}

signed main () {
	charming ();
	return 0;
}