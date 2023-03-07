#include<iostream>
#include<string>
using namespace std;

class student {
private:
	string m_name;
	int m_finalscore;
	int m_classscore;
	char m_cadre;
	char m_position;
	int m_paper;
public:
	student(){};
	void set_member(string name, int finalscore, int classscore,char cadre, char position, int paper) {
		m_name = name, m_finalscore = finalscore, m_classscore = classscore,m_cadre=cadre, m_position = position, m_paper = paper;
	};
	int reward() {	
		int sum = 0;
		if (m_finalscore > 80) {
			if (m_paper)
				sum += 8000;
		}			
		if (m_classscore > 80) {
			if (m_cadre == 'Y')
				sum += 850;
		}
		if (m_finalscore > 85) {
			if (m_classscore > 80)
				sum += 4000;
			if (m_position == 'Y')
				sum += 1000;
		}
		if (m_finalscore > 90) {
			sum+=2000;
		}
		return sum;
	}
	friend void show(student&stu) {
		cout << stu.m_name << endl << stu.reward() << endl;
	}
};

int main() {
	int N,max=0,Sum=0;
	cin >> N;
	student* stu = new student[N];
	string name;
	int finalscore;
	int classscore;
	char cadre;
	char position;
	int paper;
	for (int i = 0; i < N; ++i) {
		cin >> name >> finalscore >> classscore >> cadre >> position >> paper;
		stu[i].set_member(name, finalscore, classscore, cadre, position, paper);
		Sum += stu[i].reward();
		if (stu[i].reward() > stu[max].reward())
			max = i;
	}
	show(stu[max]);
	delete [N]stu;
	cout << Sum << endl;
}