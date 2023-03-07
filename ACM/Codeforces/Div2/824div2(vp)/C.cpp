#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int q, n;
int pre[30], nxt[30];
int fa[30], siz[30];
char ch[30];
string s, t;

void init () {
	fill (pre, pre + 30, -1);
	fill (nxt, nxt + 30, -1);
	s.clear ();
	for (int i = 0; i < 26; ++i) 
	fa[i] = i, siz[i] = 1;
}

int find (int x) {
	if (x == fa[x]) return x;
	return fa[x] = find (fa[x]);
}

void charming () {
	init ();
	cin >> n;
	cin >> t;
	for (int i = 0; i < 26; ++i) {
		ch[i] = 'a' + i;
	}
	for (auto it : t) {
		int cur = it - 'a';
		if (pre[cur] == -1) {
			for (int i = 0; i < 26; ++i) {
				if (nxt[i] != -1 || cur == i) continue;
				int fc = find (cur), fi = find (i);
				if (fc == fi) {
					if (siz[fc] != 26) continue;
				}
				else {
					fa[fc] = fi;
					siz[fi] += siz[fc];
				}
				nxt[i] = cur;
				pre[cur] = i;
				break;
			}
		}
		s += ch[pre[cur]];
	}
	cout << s << endl;
}

signed main () {
	cin >> q;
	while (q--) charming ();
	return 0;
}