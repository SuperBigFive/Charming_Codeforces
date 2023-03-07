#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n, k;
int a[maxn], cnt[maxn];
pii res = {-1, -1};

void init () {
	
}
//什么鬼！！！我以为区间也要最小！
void charming () {
	init ();
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!cnt[a[i]]) ++sum;
		++cnt[a[i]];
	}
	if (sum < k) {
		cout << res.fir << ' ' << res.se << endl;
		return;
	}
	int p_l = 1, p_r = n;
	while ((sum > k || cnt[a[p_r]] > 1) && p_r > p_l) {
		--cnt[a[p_r]];
		if (!cnt[a[p_r]]) --sum;
		--p_r;
	}
	res = {p_l, p_r};
	++p_l;
	for (p_l; p_l <= n && p_r <= n; ++p_l) {
		--cnt[a[p_l - 1]];
		if (!cnt[a[p_l - 1]]) --sum;
		while (sum < k && p_r <= n) {
			++p_r;
			if (!cnt[a[p_r]]) ++sum;
			++cnt[a[p_r]];
		}
		if (p_r <= n && p_r - p_l < res.se - res.fir) {
			res = {p_l, p_r};
		}
	}
	cout << res.fir << ' ' << res.se << endl;
}

signed main () {
	charming ();
	return 0;
}