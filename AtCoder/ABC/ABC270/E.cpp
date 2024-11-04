#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

struct Node {
	ll val;
	int tot;
}node[maxn];
ll n, k;
ll arr[maxn];

void init () {}

void charming () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		node[i].val = arr[i];
		node[i].tot = i;
	}
	sort (node + 1, node + 1 + n, [] (Node &a, Node &b) {
		return a.val < b.val;
	});	
	int num = n, last = 0;
	for (int i = 1; i <= n; ++i) {
		if ((node[i].val - last) * num < k) {
			k -= (node[i].val - last) * num;
			int j = i;
			while (node[j + 1].val == node[i].val) 
			arr[node[j++].tot] = 0;
			arr[node[j].tot] = 0;
			num -= j - i + 1;
			i = j;
			last = node[i].val;
		}
		else {
			int m = k / num, cnt = 0;
			last += m;
			for (int i = 1; i <= n && cnt < k - m * num; ++i) {
				if (arr[i]) --arr[i], ++cnt;
			}
			for (int i = 1; i <= n; ++i) {
				if (arr[i] == 0) cout << 0 << " ";
				else cout << arr[i] - last << " ";
			}
			break;
		}
	}
}

signed main () {
	charming ();
	return 0;
}