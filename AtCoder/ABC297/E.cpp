#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, k;
int a[10];

struct Node {
	int val, p;
	bool operator > (const Node &x) const {
		return (this -> val + a[this -> p]) > (x.val + a[x.p]);
	}
};

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort (a, a + n);
	int last = 0;
	priority_queue <Node, vector <Node>, greater <Node> > pq;
	pq.push ({0, 0});
	while (k) {
		Node cur = pq.top (); pq.pop ();
		if (last < cur.val + a[cur.p]) {
			--k, last = cur.val + a[cur.p];
			pq.push ({last, 0});
		}
		++cur.p;
		if (cur.p < n) pq.push (cur);
	}
	cout << last << endl;		
}

signed main () {
	charming ();
	return 0;
}