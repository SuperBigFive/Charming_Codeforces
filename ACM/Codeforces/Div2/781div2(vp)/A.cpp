#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

struct Node {
	int tot;
	int siz;
	vector <int> ch;
}node[maxn];
int t, n;
stack <int> st_val, st_time;

void init () {
	for (int i = 1; i <= n; ++i) node[i].siz = 0;
}

bool cmp (Node x, Node y) {
	return x.siz > y.siz;
}

void charming (){
	init ();
	cin >> n;
	int p;
	node[1].tot = 1;
	for (int i = 2; i <= n; ++i) {
		cin >> p;
		node[p].ch.push_back (i);
		++node[p].siz;
		node[i].tot = i;
	}
	sort (node + 1, node + 1 + n, cmp);
	int inj = 1;
	for (int i = 1; i <= n; ++i) {
		if (node[i].siz) {
			st_val.push (node[i].siz);
			st_time.push (inj);
		}
		else break;
		++inj;
	}
	++inj;
	while (!st_val.empty ()) {
		int v = st_val.top ();
		int tt = st_time.top ();
		st_val.pop ();
		st_time.pop ();
		if (inj - tt < v - 1) inj += (v - 1) - (inj - tt);
	}
	cout << inj << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
}
