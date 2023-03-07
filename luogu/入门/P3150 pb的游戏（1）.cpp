#include<iostream>
using namespace std;
int main()
{
	int Number;
	long int Value[50];
	cin >> Number;
	for (int i = 0; i < Number; ++i) {
		cin >> Value[i];
	}
	for (int i = 0; i < Number; ++i) {
		if (Value[i] % 2)
			cout << "zs wins" << endl;
		else
			cout << "pb wins" << endl;
	}
	return 0;
}