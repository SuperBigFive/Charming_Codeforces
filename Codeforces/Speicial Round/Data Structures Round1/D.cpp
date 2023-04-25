#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 15;
const int M = 2e5 + 5;

int t, n, m;
int a[N][M];
struct Nxt {
	int r, c;
	bool operator < (const Nxt &x) const {
		return a[r][c] - a[r][c - 1] > a[x.r][x.c] - a[x.r][x.c - 1];
	}
};
struct Node {
	int val = 0, cho[N];
	Nxt nxt;
	priority_queue <Nxt> pq;
	void init () {
		Nxt tmp;
		for (int i = 1; i <= n; ++i) {
			tmp.r = i, tmp.c = cho[i];
			if (tmp.c > 1) pq.push (tmp);
		}
		if (pq.size ()) nxt = pq.top ();
	}
	Node update () {
		nxt = pq.top ();
		Nxt tmp = nxt;
		pq.pop ();
		Node newNode = *this;
		--tmp.c;
		int r = nxt.r, c = nxt.c;
		--newNode.cho[r];
		newNode.val = val - a[r][c] + a[r][c - 1];
		//pq.push (tmp);
		if (tmp.c > 1) newNode.pq.push (tmp);
		if (pq.size ()) nxt = pq.top ();
		if (newNode.pq.size ()) newNode.nxt = newNode.pq.top ();
		return newNode;
	}
	bool operator < (const Node &x) const {
		auto [r1, c1] = this -> pq.top ();
		auto [r2, c2] = x.pq.top ();
		return this -> val - (a[r1][c1] - a[r1][c1 - 1]) <
		x.val - (a[r2][c2] - a[r2][c2 - 1]);
	}
};

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> POW10 (10), c (n + 5);
	POW10[0] = 1;
	for (int i = 1; i < 10; ++i) POW10[i] = POW10[i - 1] * 10;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		a[i][0] = -INT_MAX;
		for (int j = 1; j <= c[i]; ++j)
		cin >> a[i][j];
	}
	cin >> m;
	set <string> ban;
	auto num2str = [&] (int num) -> string {
		string res;
		while (num) {
			res += '0' + num % 10;
			num /= 10;
		}
		reverse (res.begin (), res.end ());
		return res;
	};
	string s;
	for (int i = 1, val; i <= m; ++i) {
		val = 0, s = '#';
		for (int j = 1, b; j <= n; ++j) {
			cin >> b;
			s += num2str (b) + '#';
		}
		ban.insert (s);
	}
	priority_queue <Node> pq;
	Node tmp;
	int cho = 0;
	s = '#';
	for (int i = 1; i <= n; ++i) {
		tmp.cho[i] = c[i];
		tmp.val += a[i][c[i]];
		s += num2str (c[i]) + '#';
	}
	tmp.init ();
	pq.push (tmp);
	int cnt = 0;
	while (cnt < m && ban.count (s)) {
		auto cur = pq.top ();
		pq.pop ();
		auto nxt = cur.update ();
		if (cur.pq.size ()) pq.push (cur);
		if (nxt.pq.size ()) pq.push (nxt);
		s = '#';
		for (int i = 1; i <= n; ++i)
		s += num2str (nxt.cho[i]) + '#';
		++cnt;
	}
	for (int i = 1, num = 0; i < s.size (); ++i) {
		if (s[i] == '#') {
			cout << num << " ";
			num = 0;
		}
		else num = num * 10 + s[i] - '0';
	}
}

signed main () {
	charming ();
	return 0;
}