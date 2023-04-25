#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n, mx;
int a[maxn], ans[maxn], digit[35];
map <int, int> num[35];

void init () {
	mx = -1;
	for (int i = 0; i < 35; ++i)
	num[i].clear (), digit[i] = ans[i] = 0;
}

void add (int val) {
	int tmp = val, cnt = 0;
	while (tmp) {
		++cnt;
		if (tmp & 1) ++num[cnt][val];
		tmp >>= 1;
	}
}

void del (int val) {
	int tmp = val, cnt = 0;
	while (tmp) {
		++cnt;
		if (tmp & 1) --num[cnt][val], digit[cnt] = 1;
		tmp >>= 1;
	}
}

void charming () {
	init ();
	scanf ("%d", &n);
	map <int, int> s;
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		mx = max (mx, a[i]);
		add (a[i]);
	}
	int cnt = 1;
	ans[1] = mx;
	del (mx);
	for (int i = 2; i <= n; ++i) {
		vector <int> pos0;
		for (int j = 30; j >= 1; --j) {
			if (digit[j] > 0) continue;
			pos0.emplace_back (j);
		}
		if (!pos0.size ()) break;
		map <int, int> *tmp1, tmp2[35];
		tmp1 = &tmp2[34];
		for (int j = 0; j < pos0.size (); ++j) {
			if (!(*tmp1).size () && num[pos0[j]].size ()) {
				tmp1 = &num[pos0[j]];
				continue;
			}
			for (auto it : num[pos0[j]]) {
				if ((*tmp1).count (it.first)) 
				++tmp2[j][it.first];
			}
			if (tmp2[j].size ()) tmp1 = &tmp2[j];
		}
		if (!(*tmp1).size ()) break;
		for (auto it : (*tmp1)) {
			del (it.first);
			ans[++cnt] = it.first;
			break;
		}
	}
	for (int i = 1; i <= cnt; ++i) {
		++s[ans[i]];
		printf ("%d ", ans[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (s.count (a[i])) {
			--s[a[i]];
			if (!s[a[i]]) s.erase (a[i]);
		}
		else printf ("%d ", a[i]);
	}
	printf ("\n");
}

signed main () {
	scanf ("%d", &t);
	while (t--) charming ();
	return 0;
}