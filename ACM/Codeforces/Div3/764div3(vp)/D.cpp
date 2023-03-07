#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

int t, n, k;
char str[maxn];
int cnt[maxn];

void init () {
	for (int i = 0; i <= 26; ++i) cnt[i] = 0;
}

void charming () {
	init ();
	cin >> n >> k;
	cin >> str + 1;
	for (int i = 1; i <= n; ++i) ++cnt[str[i]-'a'];
	int odd_num = 0;
	bool ok = true;
	for (int i = 0; i < 26; ++i) if (cnt[i] & 1) ++odd_num;
	int ans = 0, res = n - odd_num;
	ans =2*( res / (k << 1));
	res = res % (k << 1) + odd_num;
	if (res >= k) ++ans;
	//if (res + odd_num >= 2*k && )
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
