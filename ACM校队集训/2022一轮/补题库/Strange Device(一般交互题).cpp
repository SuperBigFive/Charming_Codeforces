#include <bits/stdc++.h>
#define ll long long
#define pb push_back 
#define fir first
#define se second
#define pii pair <int, int>
#define vi vector <int>
using namespace std;
const int maxn = 5e2 + 5;

int n, k;

void ask (int pos) {
	cout << "? ";
	for (int i = 1; i <= k + 1; ++i) {
		if (i == pos) continue;
		cout << i << ' ';
	}
	cout << endl;
	fflush (stdout);
}

void ans (int pos) {
	cout << "! " << pos << endl;
	fflush (stdout);
}

void charming () {
	cin >> n >> k;
	int pos, val;
	int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= k + 1; ++i) {
		ask (i);
		cin >> pos >> val;
		if (num1 == -1) {
			num1 = val;
			++cnt1;
		}
		else if (val == num1) {
			++cnt1;
		}
		else if (num2 == -1) {
			num2 = val;
			++cnt2;
		} 
		else if (val == num2) {
			++cnt2;
		}
	}
	if (num2 > num1) ans (cnt2);
	else ans (cnt1);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}