#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;

ll n, q, x, cnt ,front;
int nxt[maxn];
ll weight[maxn];
bool vis[maxn];
ll box[maxn];

void get_box () {
	ll have = 0;
	int tot = 0;
	while (have < x) have += weight[tot % n], ++tot;
	nxt[1] = tot;
	for (int i = 2; i <= n; ++i) {
		have -= weight[i - 2];
		while (have < x) have += weight[tot % n], ++tot;
		nxt[i] = tot % n + 1;
	}
	int now = 1;
	while (true) {
		if (vis[now]) break;
		vis[now] = true;
		now = nxt[now];
	}
	cnt = 0, front = 0;
	int tmp = now;
	now = 1;
	while (now != tmp) ++front, now = nxt[now];
	now = tmp;
	while (true) {
		++cnt;
		now = nxt[now];
		if (now == tmp) break;
	}
	int tot1 = 0, tot2;
	for (int i = 1; i <= front + cnt; ++i) {
		have = 0;
		tot2 = tot1;
		while (have < x) have += weight[tot1 % n], ++tot1;
		box[i] = tot1 - tot2;
	}
	
}

void charming () {
	cin >> n >> q >> x;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> weight[i];
		//weight[i] = weight[i] % n;
	}
	ll k;
	get_box ();
	for (int i = 1; i <= q; ++i) {
		cin >> k;
		if (k > front) cout << box[front + (k - front - 1) % cnt + 1] << endl;
		else cout << box[k] << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
