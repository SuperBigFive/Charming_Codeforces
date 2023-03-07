#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e2 + 5;

int t, n;
int a0[maxn], p[maxn], rk[maxn], pre[maxn];
bool vis[maxn];
vector <int> fusion[maxn<<1];

void init () {
	for (int i = 1; i <= n; ++i) pre[i] = i, rk[i] = 1;
	memset (vis, 0 , sizeof vis);
}

int find (int x) {
	if (x == find(x)) return x;
	return pre[x] = find(pre[x]); 
}

void joint (int x, int y) {
	int fx = find (x), fy = find (y);
	if (rk[fx] >= rk[fy]) {
		pre[fy] = fx;
		++rk[fx];
	}
}

void new_fusion (int cnt) {
	int tmp[maxn];
	for (int i = 0; i < fusion[cnt].size (); ++i) {
		tmp[i+1] = fusion
	}
}

void charming () {
	cin >> n;
	cin >> str;
	init ();
	for (int i = 1; i <= n; ++i) a0[i] = i, cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			int j = i;
			vis[i] = true;
			while (find (j) != find (p[i])) {
				joint (j, p[i]);
				j = p[i];
				vis[j] = true;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		fusion[find(i)].push_back (p[i]);
	}
	int tot = 200;
	for (int i = 1; i <= n; ++i) {
		if (fusion.size ()) {
			++tot;
			new_fusion (i);
		}
	}
	for (int i = 0; i < fusion[tot].size (); ++i) {
		if (fusion[tot][i]) {
			cout << i << endl;
			return;
		}
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
