#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
int ans_up[maxn], ans_down[maxn];
int pos[maxn], last_up[maxn], last_down[maxn];

void init () {
	
}

void charming () {
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		pos[x] = y;
	}
	for (int i = 1; i <= n; ++i) {
		//ans_down[i] = ans_up[i] = 1;
	}
	for (int i = 1; i < maxn; ++i) {
		if (pos[i]) {
			int y = pos[i];
			int tmp1 = ans_down[y + 1] + 1, tmp2 = ans_up[y] + 1;
			ans_down[y] = ans_down[y] - last_down[y] + tmp1;
			ans_up[y + 1] = ans_up[y + 1] - last_up[y + 1] + tmp2;
			last_down[y] = tmp1;
			last_up[y + 1] = tmp2;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans_up[i]  + ans_down[i] + 1 << ' ';
	}
	cout << endl;
}
signed main () {
	//freopen ("input.in", "r", stdin);
	charming ();
	return 0;
}