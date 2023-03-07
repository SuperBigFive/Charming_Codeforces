#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
#define format pair <int, pair <int, int > >
using namespace std;
const int maxn = 2e5 + 5;

int n;
int a[maxn], pre[maxn], nxt[maxn];
char p[maxn];
bool vis[maxn];
vector <pair <int, int> > res;

void init () {
	
}

void charming () {
	init ();
	scanf ("%d", &n);
	scanf ("%s", p + 1);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	priority_queue <format, vector <format> , greater <format> > pq;
	for (int i = 1; i < n; ++i) {
		if (p[i] != p[i + 1]) {
			pq.push ({abs (a[i] - a[i + 1]), {i, i + 1}});
		}
	}
	pair <int, pair <int, int > > now;
	for (int i = 1; i <= n; ++i) {
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	int l, r;
	while (!pq.empty ()) {
		now = pq.top ();
		pq.pop ();
		l = now.se.fir, r = now.se.se;
		if (!vis[l] && !vis[r]) {
			res.pb ({l, r});
			vis[l] = vis[r] = true;
			pre[nxt[r]] = pre[l];
			nxt[pre[l]] = nxt[r];
			if (pre[l] >= 1 && nxt[r] <= n && p[pre[l]] != p[nxt[r]]) 
			pq.push ({abs(a[pre[l]] - a[nxt[r]]), {pre[l], nxt[r]}});
		}
	}
	printf ("%d\n", res.size ());
	for (auto it : res) {
		printf ("%lld %lld\n", it.fir, it.se);
	}
}

signed main () {
	charming ();
	return 0;
}