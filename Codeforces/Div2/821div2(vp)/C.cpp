#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, tail;
int arr[maxn], stk[maxn];
vector <pair <int, int> > ans;

void init () {
	tail = 0;
	ans.clear ();
}

void charming () {
	init ();	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (((arr[i] ^ arr[1]) & 1) == 0) stk[++tail] = i;
	}
	int id = stk[tail];
	while (tail > 1) ans.emplace_back (make_pair (stk[--tail], id));
	for (int i = 2; i <= n; ++i) {
		if ((arr[i] ^ arr[1]) & 1) 
		ans.emplace_back (make_pair (1, i));
	}
	cout << ans.size () << endl;
	for (auto it : ans) cout << it.first << " " << it.second << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}