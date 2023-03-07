#include<iostream>
using namespace std;
int main() {
	int people,max=0,time=0;
	int *destination=NULL;
	cin >> people;
	destination = new int[people];
	for (int i = 0; i < people; ++i) {
		cin >> destination[i];
		if (destination[i] > max)
			max = destination[i];
	}
	int* floor_times = new int[max]();
	for (int i = 0; i < people; ++i) {
		++(floor_times[destination[i]-1]);
	}
	time += 10 * max;
	for (int i = 0; i < max; ++i) {
		if (floor_times[i])
			time += 5 + floor_times[i];
	}
	delete [people]destination;
	delete [max]floor_times;
	cout << time << endl;
	return 0;
}