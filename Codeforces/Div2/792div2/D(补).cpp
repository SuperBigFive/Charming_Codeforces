#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int t, n, k;
ll sum;
int i, j;
ll ans;
ll arr[maxn];
ll reduce[maxn];

void init () {
	sum = ans = 0;
}

void check () {}

bool cmp (ll a, ll b) {
	return a > b;
}

void solve () {
	cin >> n >> k;
	init ();
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (i = 1; i <= n; ++i) {
		reduce[i] = arr[i] - (n - i);
	}
	sort (reduce + 1, reduce + 1 + n, cmp);
	for (i = 1; i <= k; ++i) {
		sum -= reduce[i];
	}
	sum -= (ll)(k - 1)*(ll)k/2;
	cout << sum << endl;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) solve ();
}
