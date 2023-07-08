#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int t, a, b, c, x, y, z;
int arr[maxn];
char str[maxn];

void init () {}

void check () {}

void solve () {
	cin >> a >> b >> c;
	z = c;
	y = b;
	int k = (c - a)/y + 1;
	x = y*k + a;
	cout << x << " " << y << " " << z << endl;
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) solve ();
}
