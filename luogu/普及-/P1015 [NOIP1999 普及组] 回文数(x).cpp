#include<iostream>
using namespace std;

bool Judge(char* ptr);
void calculate(char* p,int n);

int length = 0;

int main() {
	int N,count=0;
	char number[32];
	cin >> N >> number;
	while (Judge(number)) {
		calculate(number,N);
		++count;
		if (count > 30) {
			cout << "Impossible!" << endl;
			return 0;
		}
	}
	cout << "STEP=" << count << endl;
	return 0;
}

bool Judge(char* ptr) {
	length = 0;
	for (; ptr[length] != '\0'; ++length) {}
	--length;
	for (int i = 0,j=length; i <= j; ++i, --j) {
		if (ptr[i] == ptr[j])
			continue;
		else return true;
	}
	return false;
}

void calculate(char* p,int n) {
	int l = length;
	for (int i = 0; i <= l; ++i, --l) {
		char temp = p[i];
		p[i] += p[l] - '0';
		p[l] += temp - '0';
	}
	for (int i = 0; i <= length; ++i) {
		if (p[i] - '0' >= n) {
			if (i == length) {
				p[i + 1] = (p[i] - '0') / n + 48;
				p[i + 2] = '\0';
			}
			else
				p[i + 1] += (p[i] - '0')/n;
			p[i] = (p[i] - '0') % n+48;
		}
	}
}