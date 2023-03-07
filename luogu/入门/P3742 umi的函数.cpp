#include<iostream>
using namespace std;
int main()
{
	int n,i=0;
	char str1[100], str2[100];
	cin >> n;
	cin >> str1 >> str2;
	for (; str1[i] != '\0'; ++i) {
		if (str1[i] < str2[i]) {
			cout << "-1" << endl;
			return 0;
		}

		else
			continue;
	}
		cout << str2 << endl;
	return 0;
}