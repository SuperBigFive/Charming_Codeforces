#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;
const int M = 26;

struct PAM {
	int n, m, cnt, last, tot;
	string s;
	vector <int> fail, len;
	vector <vector <int> > nxt;
	
	PAM (int n, int m) {
		this -> n = n, this -> m = m;
		this -> cnt = this -> last = 0;
		this -> tot = 1;
		this -> fail = this -> len = vector <int> (n + 5);
		this -> nxt = vector <vector <int> > (n + 5, vector <int> (m));
		this -> s = '#';
		fail[0] = 1, fail[1] = 1;
		len[0] = 0, len[1] = -1;
	}
	
	int Get_fail (int id) {
		while (s[cnt - len[id] - 1] != s[cnt]) id = fail[id];
		return id;
	}
	
	int Insert (char ch) {
		++cnt, s += ch;
		int ch2num = ch - 'a', cur = Get_fail (last);
		if (!nxt[cur][ch2num]) {
			++tot;
			fail[tot] = nxt[Get_fail (fail[cur])][ch2num];
			len[tot] = len[cur] + 2;
			nxt[cur][ch2num] = tot;
		}
		return last = nxt[cur][ch2num];
	}
};

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	PAM pam (N, M);
	vector <int> ans (N);
	for (int i = 0, lans, siz = s.size (), cur; i < siz; ++i) {
		if (i) s[i] = (s[i] - 97 + lans) % 26 + 97;
		cur = pam.Insert (s[i]);
		lans = (ans[cur] = ans[pam.fail[cur]] + 1);
		cout << lans << " \n"[i == siz - 1];
	}
}

signed main () {
	charming ();
	return 0;
}