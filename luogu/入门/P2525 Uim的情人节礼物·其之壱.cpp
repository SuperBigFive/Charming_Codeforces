#include<iostream>
using namespace std;	
int Order[9];

int main() {

	int Number,temp,rank[9];
	cin >> Number;
	for (int i = 0; i < Number; ++i)
		cin >> Order[i];
	int number = Number - 1,change_number=number;
	while (number > 0) {
		if (Order[number] < Order[number - 1])
		{
			change_number = number;
			break;
		}
		else {
			--number;
			if (!number) {
				cout << "ERROR" << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < Number - change_number + 1; ++i) {
		rank[i] = Order[change_number - 1 + i];
	}
	for (int i = 1; i < Number - change_number + 1; ++i) {
		for (int j = 0; j < Number - change_number + 1 - i; ++j) {
			if (rank[j] > rank[j + 1]) {
				temp = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = temp;
			}
		}
	}
	Order[change_number - 1] = rank[0];
	for (int i = Number - change_number,j=change_number; i > 0; --i,++j) {
		Order[j] = rank[i];
	}
	for (int i = 0; i < Number - 1; ++i)
		cout << Order[i] << " ";
	cout << Order[Number - 1];
	return 0;
}