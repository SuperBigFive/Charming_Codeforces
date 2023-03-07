#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
ll arr[maxn];

bool check (ll time) {
	int now = n;
	ll t, tmp;
	tmp = arr[now];
	while (!tmp && now > 0) tmp = arr[--now];
	for (int i = 1; i <= m && now; ++i) {
		t = time - now;
		while (t >= tmp && now > 0) {
			t -= tmp;
			tmp = arr[--now];
		}
		tmp -= t;
	}
	if (!now) return true;
	return false;
}

void charming () {
	cin >> n >> m;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	ll ub = sum + n;
	ll lb = 0;
	while (lb < ub) {
		ll mid = (lb + ub) / 2;
		if (check (mid)) ub = mid;
		else lb = mid + 1;
	}
	cout << lb << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
} 
