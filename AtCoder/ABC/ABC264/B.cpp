#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int r, c;
int mp[8][8] = {
1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 0, 0, 0, 0, 0, 0,
1, 0, 1, 1, 1, 1, 1, 1,
1, 0, 1, 0, 0, 0, 0, 0,
1, 0, 1, 0, 1, 1, 1, 1,
1, 0, 1, 0, 1, 0, 0, 0,
1, 0, 1, 0, 1, 0, 1, 1,
1, 0, 1, 0, 1, 0, 1, 0,
};
void init () {
	
}

void charming () {
	cin >> r >> c;
	r = min (r, 15 - r + 1), c = min (c, 15 - c + 1);
	if (mp[r - 1][c - 1]) cout << "black" << endl;
	else cout << "white" << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}