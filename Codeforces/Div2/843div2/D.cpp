#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;

int n, s, t;
vector <int> prim, len (N);
vector <vector <int> > num (N), rev (N);
vector <vector <pair <int, int> > > adj (N);

void init () {}

void get () {
	vector <int> vis (N);
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) prim.emplace_back (i);
		for (int j = 0; j < prim.size () && i * prim[j] < N; ++j) {
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
		}
	}
	for (int i = 0; i < prim.size (); ++i) {
		for (int j = prim[i]; j < N; j += prim[i]) {
			num[j].emplace_back (prim[i]);
		}
	}
}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5);
	vector <vector <int> > rev (N);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (auto it : num[a[i]]) {
			rev[it].emplace_back (i);
		}
	}
	cin >> s >> t;
	if (s == t) {
		cout << 1 << endl;
		cout << s << endl;
		return;
	}
	if (__gcd (a[s], a[t]) > 1) {
		cout << 2 << endl;
		cout << s << " " << t << endl;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < num[a[i]].size (); ++j) {
			for (int k = 0; k < num[a[i]].size (); ++k) {
				if (j == k) continue;
				adj[num[a[i]][j]].emplace_back (make_pair (num[a[i]][k], i));
			}
		}
	}
	queue <pair <int, int> > q;
	vector <int> ok (N), vis (N);
	vector <pair <int, int> > pre (N);
	for (int i = 0; i < num[a[t]].size (); ++i) ok[num[a[t]][i]] = 1;
	for (int i = 0; i < num[a[s]].size (); ++i) {
		q.push (make_pair (num[a[s]][i], s)); 
		vis[num[a[s]][i]] = 1;
	}
	while (!q.empty ()) {
		auto [u, uid] = q.front ();
		q.pop ();
		for (auto &[v, vid] : adj[u]) {
			if (vis[v]) continue;
			vis[v] = true;
			pre[v] = {u, uid};
			q.push ({v, vid});
			if (ok[v]) {
				vector <pair <int, int> > stk;
				u = v, uid = vid;
				while (pre[u].first) {
					stk.emplace_back (make_pair (u, uid));
					uid = pre[u].second, u = pre[u].first;
				}
				reverse (stk.begin (), stk.end ());
				cout << stk.size () + 2 << endl;
				cout << s << " ";
				for (int i = 0; i < stk.size (); ++i) {
					cout << stk[i].second << " ";
				}
				cout << t << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	get ();
	charming ();
	return 0;
}