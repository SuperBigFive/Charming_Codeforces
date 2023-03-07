#include<iostream>
#include<math.h>
using namespace std;
int couter = 0, sum_value, arr[20], k, N, ans = 0;
bool prime(int value) {
	for (int i = 2; i < sqrt((double)value); ++i) {
		if (value % i == 0)
			return false;
	}
	return true;
}
void dfs(int pos, int couter, int sum) {
	int i;
	if (couter == k && prime(sum)) {
		++ans;
		return;
	}
	for (i = pos; i < N; ++i) {
		dfs(i+1, couter + 1, sum + arr[i]);
	}
}
int main() {
	cin >> N >> k;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}