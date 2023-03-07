#include <bits/stdc++.h>
#define ll long long
#define int ll 
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 4e6 + 5;

int n, k;
int val[maxn], cnt[maxn], cnt_pre[maxn], sum[maxn];
int last[maxn];

void charming () {
	scanf ("%lld%lld", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", &val[i]);
		val[i] += 1e6;
	}
	for (int i = 1; i <= n; ++i) {
		++cnt_pre[val[i]];
	}
	ll res = 1;
	for (int i = 0; i < maxn; ++i) {
		if (cnt_pre[i] > res) res = cnt_pre[i];
	}
	if (k) {
		for (int i = 1; i <= n; ++i) {
			++cnt[val[i]];
			if ((k > 0 && val[i] + k > 4e6) || (k < 0 && val[i] + k < 0)) continue;
			if (cnt[val[i]] == 1) sum[val[i] + k] = 1;
			else sum[val[i] + k] += 1 - (cnt[val[i] + k] - last[val[i] + k]);
			if (sum[val[i] + k] <= 0) sum[val[i] + k] = 1;
			res = max (res, sum[val[i] + k] + cnt_pre[val[i] + k]);
			last[val[i] + k] = cnt[val[i] + k];
		}
	}
	printf ("%lld\n", res);
}

signed main () {
	charming ();
	return 0;
}