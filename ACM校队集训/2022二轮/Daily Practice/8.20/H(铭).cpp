#include <bits/stdc++.h>
#define ll long long
#define int ll
#define run(b, e) for (int i = b; i <= e; ++i)
using namespace std;
const int maxn = 1e6 + 15;
const int letter = 26;

int n, tot, cnt, last;
ll ans;
ll fail[maxn], len[maxn], cntt[maxn], in[maxn];
int trie[maxn][letter];
char tmp_c;
char str[maxn];
bool vis[30];
queue <int> pq;

void init ();
void add_node (int len);
int get_fail (int tott);
void ins (char c);
void find ();

void init () {
	tot = -1, ans = last = 0;
	add_node (0);
	add_node (-1);
	fail[0] = fail[1] = 1;
}

void add_node (int lenn) {
	len[++tot] = lenn;
	fail[tot] = 0;
}

int get_fail (int tott) {
	while (str[cnt-len[tott]-1] != str[cnt]) 
		tott = fail[tott];
	return tott;
}

void ins (char c) {
	int num = (str[++cnt] = c) - 'a';
	int now = get_fail (last);
	if (!trie[now][num]) {
		add_node (len[now] + 2);
		fail[tot] = trie[get_fail (fail[now])][num];
		++in[fail[tot]];
		trie[now][num] = tot;
	}
	last = trie[now][num];
	++cntt[last];
}

void find_topu () {
	run (1, tot) if (!in[i]) pq.push (i);
	int now;
	while (!pq.empty ()) {
		now = pq.front ();
		pq.pop ();
		if (now == 1 || now == 0) continue;
		--in[fail[now]];
		cntt[fail[now]] += cntt[now];
		if (!in[fail[now]]) pq.push (fail[now]);
	}
	ll val;
	run (1, tot) {
		if (cntt[i] && len[i] & 1) ++ans;
	} 
	run (1, n) {
		int num = str[i] - 'a' + 1;
		if (vis[num]) continue;
		vis[num] = true;
		--ans;
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> n;
	cin >> str + 1;
	init ();
	for (int i = 1; i <= n; ++i) ins (str[i]);
	find_topu ();
	return 0;
}
