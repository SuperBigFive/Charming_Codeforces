#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int n;
ll arr[maxn];

void charming () {
	int a, b;
	cin >> a >> b;
	if (abs (a - b) > 1 || (a == 0 && b == 0)) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
}

int main () {
	charming ();
	return 0;
}