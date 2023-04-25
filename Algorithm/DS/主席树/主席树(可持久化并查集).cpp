#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long
#define rg register int
using namespace std;
const int maxn = 2e5 + 5;

int read(){
	char ch = getchar();
	bool flag = true;
	while(ch < '0' || ch > '9') {
		if(ch == '-') flag = false;
		ch = getchar();
	}
	int k = ch -'0';
	while(ch = getchar(), ch <= '9' && ch >= '0') {
		k = (k<<1)+(k<<3);
		k += (ch-'0');
	}
	if(flag) return k;
	return -k;
}

int n, m, tot;
int root[maxn];
int chl[maxn << 8], chr[maxn << 8], pre[maxn << 8], het[maxn << 8];

void build (rg cnt, rg l, rg r) {
	if (l == r) {
		pre[cnt] = l;
		het[cnt] = 1;
		return;
	}
	rg mid = l + r >> 1;
	chl[cnt] = ++tot;
	build (chl[cnt], l, mid);
	chr[cnt] = ++tot;
	build (chr[cnt], mid + 1, r);
}

int find_node (rg cnt, rg pos, rg l, rg r) {
	if (l == r) return cnt;
	rg mid = l + r >> 1;
	if (pos <= mid) return find_node (chl[cnt], pos, l, mid);
	return find_node (chr[cnt], pos, mid + 1, r);
}

int find_root (rg cnt, rg pos) {
	int now = find_node (cnt, pos, 1, n);
	if (pre[now] == pos) return now;
	return find_root (cnt, pre[now]);
}

int build_new (rg old, rg pos, rg new_pre, rg l, rg r) {
	int now = ++tot;
	chl[now] = chl[old];
	chr[now] = chr[old];
	if (l == r) {
		pre[now] = new_pre;
		het[now] = het[old];
		return now;
	}
	rg mid = l + r >> 1;
	if (pos <= mid) chl[now] = build_new (chl[now], pos, new_pre, l, mid);
	else chr[now] = build_new (chr[now], pos, new_pre, mid + 1, r);
	return now;
}

void add_het (rg cnt, rg pos, rg l, rg r) {
	if (l == r) {
		++het[cnt];
		return;
	}
	rg mid = l + r >> 1;
	if (pos <= mid) add_het (chl[cnt], pos, l, mid);
	else add_het (chr[cnt], pos, mid + 1, r);
}

void charming () {
	n = read (), m = read ();
	build (0, 1, n);
	rg opt, a, b, k, root_1, root_2;
	for (rg i = 1; i <= m; ++i) {
		opt = read ();
		root[i] = root[i - 1];
		if (opt == 1) {
			a = read (), b = read ();
			root_1 = find_root (root[i - 1], a);
			root_2 = find_root (root[i - 1], b);
			if (root_1 == root_2) continue;
			if (het[root_1] > het[root_2]) swap (root_1, root_2);
			root[i] = build_new (root[i - 1], pre[root_1], pre[root_2], 1, n);
			if (het[root_1] == het[root_2]) add_het (root[i], pre[root_2], 1, n);
		}
		else if (opt == 2) {
			k = read ();
			root[i] = root[k];
		}
		else {
			a = read (), b = read ();
			root_1 = find_root (root[i - 1], a);
			root_2 = find_root (root[i - 1], b);
			if (root_1 == root_2) puts ("1");
			else puts ("0");
		}
	}
}

signed main () {
	charming ();
	return 0;
}