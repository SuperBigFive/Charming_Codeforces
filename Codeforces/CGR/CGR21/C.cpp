#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 15;

int t, n, m, k;
ll a[maxn], b[maxn];
ll powm[maxn];
ll la[maxn], ra[maxn], vala[maxn];
ll lb[maxn], rb[maxn], valb[maxn];
void init () {}

void build_powm () {
	powm[0] = 1;
	int cnt = 0;
	while (powm[cnt] < 1000000001) {
		++cnt;
		powm[cnt] = powm[cnt-1] * m;
	}
}
void charming () {
	cin >> n >> m;
	build_powm ();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		la[i] = ra[i-1] + 1;
		if (!(a[i] % m)) {
			int cnt = 0;
			while (!(a[i] % m)) ++cnt, a[i] /= m;
			ra[i] = la[i] + powm[cnt] - 1;
			vala[i] = a[i];
		}	
		else {
			ra[i] = la[i];
			vala[i] = a[i];
		}
	}
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> b[i];
		lb[i] = rb[i-1] + 1;
		if (!(b[i] % m)) {
			int cnt = 0;
			while (!(b[i] % m)) ++cnt, b[i] /= m;
			rb[i] = lb[i] + powm[cnt] - 1;
			valb[i] = b[i];
		}	
		else {
			rb[i] = lb[i];
			valb[i] = b[i];
		}
	}
	int pa1 = 1, pa2 = 1, pb1 = 1, pb2 = 1;
	while (pa1 <= n && pb1 <= k) {
		while (vala[pa2] == vala[pa1] && pa2 <= n) ++pa2;
		--pa2;
		while (valb[pb2] == valb[pb1] && pb2 <= k) ++pb2;
		--pb2;
		if (vala[pa1] != valb[pb1] || la[pa1] != lb[pb1] || ra[pa2] != rb[pb2]) {
			cout << "NO" << endl;
			return;
		}
		pa1 = pa2 = pa2 + 1;
		pb1 = pb2 = pb2 + 1;
	}
	if (rb[k] == ra[n]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
