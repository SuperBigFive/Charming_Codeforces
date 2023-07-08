#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void add (int x) {
	cout << "+ " << x << endl;
	cout.flush ();
	int tmp;
	cin >> tmp;
}

int ask_dis (int i, int j) {
	cout << "? " << i << " " << j << endl;
	cout.flush ();
	int tmp;
	cin >> tmp;
	return tmp;
}

void answer (vector <int> &a, vector <int> &b) {
	cout << "! ";
	for (int i = 1; i <= n; ++i) cout << a[i] << " ";
	for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i == n];
	cout.flush ();
	int tmp;
	cin >> tmp;
}


void charming () {
	init ();
	cin >> n;
	add (n + 1), add (n + 2);
	vector <int> node (n + 5);
	for (int i = 1, j = 1, rev = 0; i <= n; ++i) {
		node[j] = i;
		j += 2 * (rev ? -1 : 1);
		if (j > n) j = n - (n & 1), rev = 1;
	}
	vector <pair <int, int> > dis;
	for (int i = 2; i <= n; ++i) {
		dis.emplace_back (make_pair (ask_dis (1, i), i));
	}
	auto [mx_dis, id] = *max_element (dis.begin (), dis.end ());
	vector <int> p1 (n + 5), p2 (n + 5);
	p1[id] = node[1], p2[id] = node[n];
	for (int i = 1, ndis; i <= n; ++i) {
		if (i == id) continue;
		ndis = ask_dis (id, i);
		p1[i] = node[1 + ndis];
		p2[i] = node[n - ndis];
	}
	answer (p1, p2);
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
