
#include<iostream>
using namespace std;

int main() {
	int passenger_begin, stations, passenger_end, target_station,second;
	cin >> passenger_begin >> stations >> passenger_end >> target_station;
	int* fibo = new int[stations-1];
	fibo[0] = 1, fibo[1] = 1;
	for (int i = 2; i < stations - 1; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	second = (passenger_end - passenger_begin*(fibo[stations-4]+1)) / (fibo[stations - 3] - 1);
	if (target_station < 3)
		cout << passenger_begin;
	else
		target_station = passenger_begin * fibo[target_station - 3] + second * fibo[target_station - 2] + passenger_begin - second;
	cout << target_station;
	delete [stations]fibo;
	return 0;
}