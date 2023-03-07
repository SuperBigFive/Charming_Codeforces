#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 32768;

int n, num, tot, mmin;
int arr[17], pow2[17], cost[17];
int i, j, k;

void init () {
	mmin = INT_MAX;
}

bool valid () {}

void get_digit (int numm) {
	tot = 0;
	while (numm) {
		++tot;
		numm /= 2;
	}
}

void build () {
	int tmp = 1;
	pow2[0] = 0;
	for (i = 1; i <= 16; ++i) {
		pow2[i] = tmp;
		tmp = tmp << 1;
	}
}

void solve () {
	cin >> n;
	build ();
	for (i = 1; i<= n; ++i) {
		init ();
		cin >> num;
		get_digit (num);
		if (num == mod || !num) {
			cout << 0 << " " ;
			continue;
		}
		for (j = 1; j <= tot; ++j) {
			int cost_tmp = num & (pow2[j+1] - 1);
			if (cost_tmp) cost[j] = pow2[j+1] - cost_tmp + 15 - j;
			else cost[j] = 15 - j;
 		}
			//cost[j] =  pow2[j+1] - (num & (pow2[j+1] - 1)) + 15 - j;
		for (j = 1; j <= tot; ++j) 
			mmin = min (mmin, cost[j]);
		cout << mmin << " ";
	}
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	solve ();
}
