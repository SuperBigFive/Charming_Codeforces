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
const int maxn = 2e5 + 5;

struct L {
	int val;
	int tot;
}l[maxn];
int n, m;
ll a[maxn], cnt[maxn], res[maxn];

void init () {
	
}

void charming () {
	cin >> n >> m;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!cnt[a[i]]) ++sum;
		++cnt[a[i]];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> l[i].val;
		l[i].tot = i;
	}
	sort (l + 1, l + 1 + m, [] (L a, L b) {
		//if (a.val == b.val) return a.tot < b.tot;
		return a. val < b.val;
	});
	int p = 1;
	for (int i = 1; i <= m; ++i) {
		while (p < l[i].val && p <= n) {
			--cnt[a[p]];
			if (cnt[a[p]] <= 0) --sum;
			++p;
		}
		res[l[i].tot] = sum;
	}
	for (int i = 1; i <= m; ++i) {
		cout << res[i] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}