#include<iostream>
using namespace std;

bool DorS_single(int number);
int DorS_all(int number1);
static int arr_all[9];
static int arr[3];

int main() {
	for (int i = 123; i < 333; ++i) {
		if (DorS_all(i)) {
			cout << i << " " << 2 * i << " " << 3 * i<<" "<<endl;
		}
		else
			continue;
	}
}

bool DorS_single(int number) {

	arr[0] = number / 100;
	number = number % 100;
	arr[1] = number / 10;
	number = number % 10;
	arr[2] = number;
	return arr[0] != arr[1] && arr[0] != arr[2] && arr[1] != arr[2];
}
int DorS_all(int number1) {
	int number2 = 2 * number1, number3 = 3 * number1;
	for (int i = 0,j=0; i < 3; ++i) {
		switch (i) {
		case 0: {
			DorS_single(number1);
			break;
		}
		case 1: {
			DorS_single(number2);
			break;
		}
		case 2: {
			DorS_single(number3);
			break;
		}
		}
		arr_all[j++] = arr[0];
		arr_all[j++] = arr[1];
		arr_all[j++] = arr[2];
	}
	bool flag = DorS_single(number1) && DorS_single(number2) && DorS_single(number3);
	if (flag) {
		int n[10] = { 0 };
		for (int i = 0; i < 9; ++i) {
			++n[arr_all[i]];
			if (n[0])
				return 0;
			if (n[arr_all[i]] == 2)
				return 0;
		}
		return 1;
	}
	else
		return 0;
}