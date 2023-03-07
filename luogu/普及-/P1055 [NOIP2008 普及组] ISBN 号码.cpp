#include<iostream>
using namespace std;

int Calculate_ISBN(int *Number);

int main() {
	char number[13];
	for (int i = 0; i < 13; ++i) {
		cin >> number[i];
	}
	int math_number[9] = { number[0]-48,number[2]-48,number[3]-48,number[4]-48,number[6]-48,number[7]-48,number[8]-48,number[9]-48,number[10]-48};
	bool flag = number[12] == 'X' ? Calculate_ISBN(math_number) == 10 : Calculate_ISBN(math_number) == number[12] - 48;
	if (flag)
		cout << "Right" << endl;
	else {
		for (int i = 0; i < 12; ++i) {
			cout << number[i];
		}
		if (Calculate_ISBN(math_number) == 10)
			cout << "X" << endl;
		else
			cout << Calculate_ISBN(math_number) << endl;
	}
	return 0;
}

int Calculate_ISBN(int *Number) {
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		sum += Number[i] * (i+1);
	}
	sum = sum % 11;
	return sum;
}