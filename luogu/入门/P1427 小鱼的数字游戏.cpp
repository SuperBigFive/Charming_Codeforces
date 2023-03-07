#include<iostream>
using namespace std;

int arr[100];

int main() {
	int i = 0;
	do {
		cin >> arr[i];
		i++;
	} while (arr[i - 1]);
	for (i = i - 2; i > 0; --i)
		cout << arr[i] << " ";
	cout << arr[0] << endl;
	return 0;
}