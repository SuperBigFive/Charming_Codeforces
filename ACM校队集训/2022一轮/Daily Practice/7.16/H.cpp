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
	cin >> n;
	if (n == 1) cout << "D" << endl;
	else if (n == 2) cout << "C" << endl;
	else if (n == 3) cout << "B" << endl;
	else if (n == 4) cout << "D" << endl;
	else if (n == 5) cout << "A" << endl;
	else if (n == 6) cout << "C" << endl;
	else if (n == 7) cout << "C" << endl;
	else cout << "D" << endl;
}

int main () {
	charming ();
	return 0;
}