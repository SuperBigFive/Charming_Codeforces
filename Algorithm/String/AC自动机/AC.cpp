#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 26;

struct AC {
	int n, tot;
	string s;
	vector <int> fail, ans, in;
	vector <vector <int> > nxt, id;
	
	AC (string s) {
		this -> n = s.size (), this -> tot = 0;
		this -> s = '#' + s;
		this -> fail = this -> ans = this -> in = vector <int> (N);
		this -> nxt = vector <vector <int> > (N, vector <int> (M));
		this -> id = vector <vector <int> > (N);
	}
	
	void Insert (string t, int tid) {
		int cur = 0, ch2num;
		for (char ch : t) {
			ch2num = ch - 'a';
			if (!nxt[cur][ch2num]) nxt[cur][ch2num] = ++tot;
			cur = nxt[cur][ch2num];
		}
		id[cur].emplace_back (tid);
	}
	
	void Get_fail () {
		queue <int> q;
		for (int i = 0; i < M; ++i) if (nxt[0][i]) {
			q.push (nxt[0][i]);
		}
		while (!q.empty ()) {
			int u = q.front ();
			q.pop ();
			for (int i = 0; i < M; ++i) {
				if (nxt[u][i]) {
					fail[nxt[u][i]] = nxt[fail[u]][i];
					++in[fail[nxt[u][i]]];
					q.push (nxt[u][i]);
				}
				else nxt[u][i] = nxt[fail[u]][i];
			}
		}
	}
	
	void Match () {
		for (int i = 1, j = 0, ch2num; i <= n; ++i) {
			ch2num = s[i] - 'a';
			j = nxt[j][ch2num];
			++ans[j];
		}
	}
	
	void Topu () {
		queue <int> q;
		for (int i = 1; i <= tot; ++i) if (!in[i]) q.push (i);
		while (!q.empty ()) {
			int u = q.front ();
			q.pop ();
			ans[fail[u]] += ans[u];
			if ((--in[fail[u]]) == 0 && fail[u]) q.push (fail[u]);
		}
	}
};

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	if (n == 0) exit (0);
	string s;
	vector <string> t (n);
	for (int i = 0; i < n; ++i) cin >> t[i];
	cin >> s;
	AC ac (s);
	for (int i = 0; i < n; ++i) {
		ac.Insert (t[i], i);
	}
	ac.Get_fail ();
	ac.Match ();
	ac.Topu ();
	vector <int> ans (n);
	for (int i = 1; i < N; ++i)
	for (int tid : ac.id[i]) ans[tid] = ac.ans[i];
	for (int i = 0; i < n; ++i) cout << ans[i] << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}