#include<iostream>
using namespace std;

int main() {
	int N,Count=0;
	cin >> N;	
	if (N < 3) {
		cout << "0" << endl;
		return 0;
	}
	int *ptr = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> ptr[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j == i)
				continue;
			for (int k = j+1; k < N; ++k) {
				if(k == i)
					continue;
				if (ptr[j] + ptr[k] == ptr[i]) {
					++Count;
					k = N;
					j = N;
				}

			}
		}
	}
	cout << Count << endl;
	delete [N]ptr;
	return 0;
}