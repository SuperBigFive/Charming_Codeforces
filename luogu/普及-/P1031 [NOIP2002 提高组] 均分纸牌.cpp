#include<iostream>
using namespace std;
int main() {
	int N,sum=0,times=0;
	cin >> N;
	int* ptr = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> ptr[i];
		sum += ptr[i];
	}
	int average = sum / N;
	for (int i = 0; i < N; ++i) {
		ptr[i] -= average;
	}
	for (int i = 0; i < N - 1; ++i) {
		if (ptr[i]) {
			++times;
			ptr[i + 1] += ptr[i];
		}
	}
	cout << times << endl;
	delete [N]ptr;
	return 0;
}