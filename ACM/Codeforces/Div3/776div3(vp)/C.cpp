#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

struct Node {
	int pos;
	int val;
	int id;
}node[maxn];
int t, n, m;

bool cmp1 (Node x, Node y) {
	return x.val < y.val;
}

bool cmp2 (Node x, Node y) {
	return x.pos < y.pos;
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> node[i].pos >> node[i].val;
		node[i].id = i;
	}
	sort (node + 1, node + 1 + m, cmp1);
	sort (node + 1, node + 1 + 2 * n, cmp2);
	ll ans = 0;
	for (int i = 1; i <= 2 * n; ++i) ans += node[i].val;
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		cout << node[i].id << " " << node[2 * n - i + 1].id << endl;
	} 
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
}
