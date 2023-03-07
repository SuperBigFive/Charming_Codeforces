#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, head;
int a[maxn], b[maxn];
int stk[maxn];

void init () {
	head = 0;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	ll res = 0;
	for (int i = 1; i <= n; ++i)
	res += abs (a[i] - b[i]);
	cout << res << endl;
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= b[i]) {
			stk[++head] = i;
			continue;
		}
		while (head && 
		b[stk[head]] - a[stk[head]] <= a[i] - b[stk[head]]) {
			cout << stk[head--] << ' ';
		}
		cout << i << ' ';
	}
	while (head) {
		cout << stk[head--] << ' ';
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}