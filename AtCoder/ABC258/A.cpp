#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

int n;

void charming () {
	int k;
	cin >> k;
	if (k >= 60) {
		cout << "22:";
		int m = k % 60;
		if (!m) cout << "00" << endl;
		else if (m < 10) cout << "0" << m << endl;
		else cout << m << endl;
	}
	else {
		cout << "21:";
		int m = k % 60;
		if (!m) cout << "00" << endl;
		else if (m < 10) cout << "0" << m << endl;
		else cout << m << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
