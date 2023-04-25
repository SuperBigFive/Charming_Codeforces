#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
template <typename T> void read(T & x){
	x = 0;
	ll f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar ()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar ()) x = x * 10 + ch - '0';
	x *= f;
}

struct Node {
	int tot;
	ll pos;
}node[maxn];
int t, n;
ll arr[maxn];
ll mmin[maxn], mmax[maxn];

bool cmp (Node a, Node b) {
	return a.pos < b.pos;
}

void init () {
	
}


void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> node[i].pos, node[i].tot = i;
	sort (node + 1, node + 1 + n, cmp);
	mmin[node[1].tot] = node[2].pos - node[1].pos;
	mmin[node[n].tot] = node[n].pos - node[n - 1].pos;
	mmax[node[1].tot] = node[n].pos - node[1].pos;
	mmax[node[n].tot] = node[n].pos - node[1].pos;
	for (int i = 2; i < n; ++i) {
		mmin[node[i].tot] = min (node[i + 1].pos - node[i].pos, node[i].pos - node[i - 1].pos);
		mmax[node[i].tot] = max (node[n].pos - node[i].pos, node[i].pos - node[1].pos);
	}
	for (int i = 1; i <= n; ++i) {
		cout << mmin[i] << " " << mmax[i] << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
} 
