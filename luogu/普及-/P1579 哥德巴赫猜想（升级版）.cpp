#include<iostream>
#include<cmath>
using namespace std;
bool Prime_number(int value);

int main() {
	int N, j = 1;
	cin >> N;
	int* ptr = new int[N/3];
	ptr[0] = 2;
	for (int i = 2 ; i < N; i += 2) {
		if (Prime_number(i)) {
			ptr[j] = i;
			++j;
		}
		if (i == 2)
			--i;
	}
	int length = j;
	for (int i = 0; i < length; ++i) {
		for (j = i; j < length; ++j) {
			if(Prime_number(N-ptr[i]-ptr[j])){
				cout << ptr[i] << " " << ptr[j] << " " << N - ptr[i] - ptr[j] << endl;
				delete [N / 3]ptr;
				return 0;
			}
		}
	}
}

bool Prime_number(int number) {
	for (int i = 2; i * i <= number+1; ++i) {
		if (number % i == 0)
			return false;
	}
	if (number < 3)
		return false;
	return true;
}