#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int n, x, y;

void charming () {
	cin >> n >> x >> y;
	int red = 1, blue = 0;
	while (n > 1) {
		--n;
		blue += red * x;
		red += blue;
		blue = blue * y;
	}
	cout << blue << endl;
}

signed main () {
	charming ();
	return 0;
}