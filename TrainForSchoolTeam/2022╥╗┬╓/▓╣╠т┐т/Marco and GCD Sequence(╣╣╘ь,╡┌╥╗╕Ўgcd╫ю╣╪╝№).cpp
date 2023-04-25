#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;
template <class T> void read (T & x){
    x = 0;
	int f = 1;
	char c = getchar ();
    while (c < '0' || c > '9') {
		if (c == '-') f = -1; 
		c = getchar ();
	}
    while (c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar ();
	}
    x *= f;
}

int n;
int GCD[maxn];

void charming () {
	cin >> n;
	int cnt = 0;
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		cin >> GCD[i];
		if (GCD[i] % GCD[1]) ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
		return;
	}
	cout << 2 * n << endl;
	for (int i = 1; i <= n; ++i) {
		cout << GCD[i] << " " << GCD[1] << " ";
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
} 
