#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
vector <int> arr;
map <int, int> cnt;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	ll sum = 0;
	for (int i = 1, a; i <= n; ++i) {
		cin >> a;
		++cnt[a];
		sum += a;
		arr.emplace_back (a);
	}
	int p1 = 0, p2 = m - 1;
	ll sum1 = 0, sum2 = 0;
	while (cnt.count (p1) && p1 <= m - 1) sum1 += p1 * cnt[p1], ++p1;
	while (cnt.count (p2) && p2 >= 0) sum2 += p2 * cnt[p2], --p2;
	if (p1 > m - 1 || p2 < 0) {
		cout << 0 << endl;
		return;	
	}
	ll res = sum - sum1 - sum2;
	sort (arr.begin (), arr.end ());
	int len = unique (arr.begin (), arr.end ()) - arr.begin ();
	p1 = lower_bound (arr.begin (), arr.begin () + len, p1) - arr.begin ();
	p2 = lower_bound (arr.begin (), arr.begin () + len, p2) - arr.begin ();
	for (int i = p1, j; i < p2; i = j + 1) {
		j = i;
		ll sum3 = 0;
		while (j + 1 < p2 && arr[j + 1] == arr[j] + 1) 
		sum3 += arr[j] * cnt[arr[j]], ++j;
		sum3 += arr[j] * cnt[arr[j]];
		res = min (res, sum - sum3);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}