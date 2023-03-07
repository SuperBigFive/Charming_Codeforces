#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 2e6 + 5;

ll a, b, k, tot1, tot2, tot;
ll aa[maxn], bb[maxn];

void init () {
	for (int i = 1; i < maxn; ++i) aa[i] = bb[i] = 0;
}

void trans () {
	while (a) {
		aa[++tot1] = a % k;
		a = (a - a % k) / k;
	}
	while (b) {
		bb[++tot2] = b % k;
		b = (b - b % k) / k;
	}
	tot = max (tot1, tot2);
}

ll cal_ () {
	ll res = 0, tmp = 0;
	for (int i = 1; i <= tot; ++i) {
		tmp = (aa[i] + bb[i] + tmp) / k;
		res += tmp;
	}	
	return res;
}

void charming () {
	init ();
	cin >> a >> b >> k;
	trans ();
	cout << cal_ () << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
