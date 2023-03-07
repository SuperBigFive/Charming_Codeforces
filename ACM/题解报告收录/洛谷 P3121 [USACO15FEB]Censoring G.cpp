#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

int n, tot, tail;
int fail[maxn];
int dep[maxn], stk[maxn];
int trie[maxn][26];
bool en[maxn];
string s, t, ans;

void init () {}

void ins () {
	int now = 0, num;
	for (auto it : t) {
		num = it - 'a';
		if (!trie[now][num]) trie[now][num] = ++tot;
		now = trie[now][num];
	}
	en[now] = true;
}

void bfs () {
	queue <int> q;
	for (int i = 0; i < 26; ++i) if (trie[0][i]) {
		q.push (trie[0][i]);
		dep[trie[0][i]] = 1;
	}
	int now;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		for (int i = 0; i < 26; ++i) {
			if (trie[now][i]) {
				fail[trie[now][i]] = trie[fail[now]][i];
				q.push (trie[now][i]);
				en[trie[now][i]] |= en[fail[trie[now][i]]];
				dep[trie[now][i]] = dep[now] + 1;
			}
			else trie[now][i] = trie[fail[now]][i];
		}
	}
}

void charming () {
	cin >> s;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		ins ();
	}
	bfs ();
	int now = 0, num;
	bool ok;
	for (int i = 0; i < s.length (); ++i) {
		num = s[i] - 'a';
		now = trie[now][num];
		if (en[now]) {
			for (int j = 1; j < dep[now]; ++j) ans.pop_back ();
			tail -= dep[now] - 1;
			now = stk[tail];
		}
		else stk[++tail] = now, ans += s[i];
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}