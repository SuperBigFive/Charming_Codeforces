#include <bits/stdc++.h>
#define ll long long
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int a[maxn], b[maxn];
vector <pair <int, int> > L[maxn];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq; 

void init () {
	for (int i = 1; i <= n; ++i) {
		L[i].clear ();
	}
	while (!pq.empty ()) pq.pop ();
}

void charming () {
	init ();
	cin >> n;
	int l, r;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		l = i / (b[i] + 1) + 1;
		r = b[i] ? i / b[i] : n;
		L[l].pb ({r, i});
	}
	for (int i = 1; i <= n; ++i) {
		for (auto it : L[i]) {
			pq.push (it);
		}
		pair <int, int> id = pq.top ();
		pq.pop ();
		a[id.se] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}