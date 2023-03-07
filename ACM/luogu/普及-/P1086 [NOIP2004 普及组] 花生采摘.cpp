#include<iostream>
#include<math.h>
using namespace std;
class maps {
public:
	int value; int m; int n;
	friend int consume(maps& map1, maps& map2) {
		int distance = 0;
		distance += map1.m > map2.m ? map1.m - map2.m : map2.m - map1.m;
		distance += map1.n > map2.n ? map1.n - map2.n : map2.n - map1.n;
		return distance;
	}
};


int main() {
	int M, N, time,sum=0;
	cin >> M >> N >> time;
	maps* map = new maps[M * 20];
	maps temp;
	for (int i = 0; i < M * N; ++i) {
		cin >> map[i].value;
		map[i].m = (i) / N+1;
		map[i].n = (i + 1) % N == 0?N:(i + 1) % N;
	}
	for (int i = 1; i < M * N; ++i) {
		for (int j = 0; j < M * N - i; ++j) {
			if (map[j].value < map[j + 1].value) {
				temp = map[j];
				map[j] = map[j + 1];
				map[j + 1] = temp;
			}
		}
	}
	if (2 * map[0].m + 1 > time) {
		cout << 0 << endl;
		delete [M * 20]map;
		return 0;
	}
	else {
		sum += map[0].value;
		time -= map[0].m+1;
		for (int i =1;; ++i) {
			if (consume(map[i], map[i - 1]) + 1 + map[i].m > time)
				break;
			sum += map[i].value;
			time -= consume(map[i], map[i - 1]) + 1;
		}
	}
	cout << sum << endl;
	delete [M * 20]map;
	return 0;
}