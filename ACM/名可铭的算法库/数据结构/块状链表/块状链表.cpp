#include <iostream>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1e3 + 5;
const int maxsize = 5e3 + 5;

struct Node {
	int nex;
	int size;
	char str[maxsize];
	
	void push_back (char ch) {
		this -> str[++size] = ch;
	}
}node[maxn << 1];

int q, tot, tail;
char ch;
char s[maxn*maxsize];

void init () {
	for (int i = 1; i < maxn; ++i) {
		node[i].nex = i + 1;
		node[i].size = 0;
	}
}

void split (int tott) {
	node[++tot].nex = node[tott].nex;
	node[tott].nex = tot;
	for (int i = node[tott].size/2 + 1; i <= node[tott].size; ++i) {
		node[tot].push_back (node[tott].str[i]);
	}
	node[tott].size >>= 1;
	if (tott = tail) tail = tot;
}

void insert (char ch, int pos) {
	int endd = 0, now = 1;
	while (endd + node[now].size < pos && now != tail) {
		endd += node[now].size;
		now = node[now].nex;
	}
	endd = pos - endd;
	if (now == tail && endd > node[now].size) node[now].push_back (ch);
	else {
		for (int i = node[now].size + 1; i > endd; --i) node[now].str[i] = node[now].str[i-1];
		node[now].str[endd] = ch;
		++node[now].size;
	}
	if (node[now].size > 5000) split (now);
}

char find_ch (int pos) {
	int endd = 0, now = 1;
	while (endd + node[now].size < pos) {
		endd += node[now].size;
		now = node[now].nex;
	}
	endd = pos - endd;
	return node[now].str[endd];
}

void charming () {
	init ();
	cin >> s + 1;
	int len = strlen (s + 1);
	int cnt = 1;
	for (int i = 1; i <= len; ++i) {
		tot = (cnt++ - 1)/4500 + 1;
		node[tot].push_back (s[i]);
	}
	tail = tot;
	cin >> q;
	char opt;
	int pos;
	for (int i = 1; i <= q; ++i) {
		cin >> opt;
		if (opt == 'Q') {
			cin >> pos;
			cout << find_ch (pos) << endl;
		}
		else {
			cin >> ch >> pos;
			insert (ch, pos);
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
}
