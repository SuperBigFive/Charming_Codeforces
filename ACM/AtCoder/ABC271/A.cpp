#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
char num[17];
void init () {}

void charming () {
	cin >> n;
	int x = n / 16, y = n % 16;
	for (int i = 0; i < 10; ++i)
	num[i] = '0' + i;
	num[10] = 'A';
	num[11] = 'B';
	num[12] = 'C';
	num[13] = 'D';
	num[14] = 'E';
	num[15] = 'F';
	cout << num[x] << num[y] << endl;
}

signed main () {
	charming ();
	return 0;
}