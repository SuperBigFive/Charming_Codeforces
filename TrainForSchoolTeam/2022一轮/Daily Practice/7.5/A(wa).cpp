#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
const ll s0 = 1611516670;
const ll M = 1099511627776;

int N;
ll s[maxn];
ll f () {
	for (int i = 1; i <= maxn; ++i) {
		s[i] = (s[i-1] + (s[i-1] >> 20) + 12345) % M;
	}
}

init () {}

void charming () {
	init ();
	f ();
	s[0] = s0;
	for (int i = 1; i <= 1000; ++i) {
		cout << s[i] << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming (); 
	
	cout << (ll)(50000 * 12345)/(1 << 20) << endl;
	cout << (1 << 20 ) << endl;
}
