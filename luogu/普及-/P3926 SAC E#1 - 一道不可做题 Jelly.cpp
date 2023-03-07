#include<iostream>
using namespace std;

int main() {
	long long Start, Point, V_b, V_ing, V_a, time;
	cin >> Start >> Point >> V_b >> V_ing >> V_a >> time;
	if (Start <= Point) {
		if (V_b * (Point - Start) < time) {
			if (time < V_b * (Point - Start) + V_ing)
				cout << Point << endl;
			else
				cout << (time - V_b * (Point - Start) - V_ing) / V_a + Point;
		}
		else
			cout << Start + time / V_b << endl;
	}
	else
		cout << Start + time/V_a;
	return 0;
}