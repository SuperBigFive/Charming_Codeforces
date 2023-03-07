#include<iostream>
using namespace std;
class student {
public:
	int m_id;
	int m_chinese;
	int m_math;
	int m_english;
	int m_sum=0;
	void set_marks(int id, int chinese, int math, int english)  {
		m_id = id;
		m_chinese = chinese;
		m_math = math;
		m_english = english;
		m_sum += m_chinese + m_math + m_english;
	};

};

void Rank(student& stu1, student& stu2) {
	if (stu1.m_sum > stu2.m_sum) {
		swap(stu1, stu2);
	}
	if (stu1.m_sum == stu2.m_sum) {
		if (stu1.m_chinese > stu2.m_chinese) {
			swap(stu1, stu2);
		}
		if (stu1.m_chinese == stu2.m_chinese) {
			if (stu1.m_id < stu2.m_id) {
				swap(stu1, stu2);
			}
		}
	}
}
void swap(student& stu1, student& stu2) {
	student temp;
	temp = stu1;
	stu1 = stu2;
	stu2 = temp;
}


int main() {
	int N;
	cin >> N;
	student stu[300];
	int chinese, english, math;
	cin >> chinese >> math >> english;
	stu[0].set_marks(1,chinese, math, english);
	for (int i = 1; i < N; ++i) {
		cin >> chinese >> math >> english;
		stu[i].set_marks(i + 1, chinese, math, english);
		for (int j = i; j > 0; --j) {
			Rank(stu[j], stu[j - 1]);
		}

	}
	for (int i = 0; i < 5; ++i) {
		cout << stu[i].m_id << " " << stu[i].m_sum << endl;
	}
	return 0;
}