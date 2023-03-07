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

int t;
double p, q;

void init () {
	
}

bool check () {
	if (p >= q) return true;
	else return false;
}

void charming () {
	init ();
	cin >> p >> q;
	if (p <= q) cout << "N0 M0R3 BL4CK 1CE TEA!" << endl;
	else cout << "ENJ0Y YOURS3LF!" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
} 
