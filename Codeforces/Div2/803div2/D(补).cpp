#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e4 + 5;

int t, n;
int arr[maxn];
int start, endd, mid;

bool valid () {
	int cnt = 0;
	for (int i = start; i <= mid; ++i) {
		cin >> arr[i];
		if (arr[i] > mid || arr[i] < start) ++cnt;
	}	
	if ((cnt & 1) == ((mid - start + 1) & 1)) return false;
	return true;
}

void charming () {
	cin >> n;
	start = 1, endd = n, mid = (n - 1)/2;
	int cntt = 0;
	while (true) {
		if (start == endd) {
			cout << "! " << start << endl;
			fflush (stdout);
			return; 
		}
		mid = (endd + start)/2;
		cout << "? " << start << " " << mid << endl;
		fflush (stdout);
		if (valid ()) endd = mid;
		else start = mid + 1;
	}
}

int main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
