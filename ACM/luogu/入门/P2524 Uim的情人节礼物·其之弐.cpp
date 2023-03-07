#include<iostream>
using namespace std;
int JC(int number);
int CF(int number, int cf);

int main() {
	int Number, order,Order[9], Rank[9] = { 0 },rank=1;
	cin >> Number;
	cin >> order;
	for (int i = 0; i < Number; ++i) {
		Order[i] = order / CF(10, Number - i-1);
		order = order % CF(10, Number - i-1);
	}

	for (int i = 0; i < Number; ++i) {
		for (int j = i+1; j < Number; ++j) {
			if (Order[i] > Order[j])
				++Rank[i];
		}
	}
	for (int i = 0; i < Number; ++i) {
		rank += JC(Number - i) * Rank[i];
	}
	cout << rank << endl;
	return 0;
}

int JC(int number) {
	int sum = 1;
	for (int i = number - 1; i > 0; --i) {
		sum *= i;
	}
	return sum;
}
int CF(int number, int cf) {
	int sum = 1;
	for (int i = 1; i <= cf; ++i)
		sum *= number;
	return sum;
}