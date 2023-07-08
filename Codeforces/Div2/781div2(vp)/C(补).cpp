#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

struct Node {
	int tot;
	int siz;
}node[maxn];
int t, n;
int arr[maxn], val[maxn], tim[maxn];
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
		++node[p].siz;
		node[i].tot = i;
	}
	sort (node + 1, node + 1 + n, cmp);
	int inj = 1, tott = 0;
	for (int i = 1; i <= n; ++i) {
		if (node[i].siz) {
			val[++tott] = node[i].siz;
			tim[tott] = inj;
		}
		else break;
		++inj;
	}
	priority_queue <int, vector <int>, greater<int> > pq;
	for (int i = 1; i <= tott; ++i) {
		if (val[i] - 1 - (inj - tim[i]) > 0) pq.push (val[i] - 1 - (inj - tim[i]));
	}
	int tmp;
	tott = 0;
	while (!pq.empty ()) {
		tmp = pq.top ();
		pq.pop ();
		arr[++tott] = tmp;
	}
	int time_go = 0;
	if (tott) {
		int now = tott;
		arr[0] = -1;
		while (true) {
			++time_go;
			if (arr[now] == arr[now - 1]) --arr[now], --now;
			else --arr[now], now = tott;
			int mmax = -1;
			for (int i = 1; i <= tott; ++i) mmax = max (mmax, arr[i]);
			if (time_go >= mmax) break;
		}
	}
	cout << inj  + time_go << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
}
