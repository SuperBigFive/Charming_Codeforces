#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

int t, n;

void charming () {
	int a, b, c;
	cin >> a >> b >> c;
	if (2*b-c > 0 && !((2*b-c)%a)) cout << "YES" << endl;
	else if (!((a+c)&1) && !(((a+c)/2)%b)) cout << "YES" << endl;
	else if (2*b-a > 0 && !((2*b-a)%c)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--)
		charming ();
	return 0;
}
