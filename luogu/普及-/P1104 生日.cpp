#include<iostream>
#include<string>
using namespace std;
class member {
private:
	string m_name;
	int m_year;
	int m_month;
	int m_day;
	int m_order;
public:
	void set_number(string name, int year, int month, int day,int order) {
		m_name = name, m_year = year, m_month = month, m_day = day; m_order = order;
	}
	member() {};
	int get_year() { return m_year; }
	int get_month() { return m_month; }
	int get_day() { return m_day; }
	int get_order() { return m_order; }
	void show_internation() {
		cout << m_name<<endl;
	}
};

int main() {
	int number;
	cin >> number;
	member* p = new member[100]();
	member* ptr = p;
	for (int i = 0; i < number; ++i) {
		string name;
		int year;
		int month; 
		int day;
		cin >> name >> year >> month >> day;
		ptr->member::set_number(name,year,month,day,i);
		++ptr;
	}
	member temp;
	for (int i = 1; i < number; ++i) {
		for (int j = 0; j < number - i; ++j) {
			if (p[j].member::get_year() > p[j + 1].member::get_year()) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
			if (p[j].member::get_year() == p[j + 1].member::get_year() && p[j].member::get_month() > p[j + 1].member::get_month()) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
			if (p[j].member::get_year() == p[j + 1].member::get_year() && p[j].member::get_month() == p[j + 1].member::get_month() && p[j].member::get_day() > p[j + 1].member::get_day()) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
			if (p[j].member::get_year() == p[j + 1].member::get_year() && p[j].member::get_month() == p[j + 1].member::get_month() && p[j].member::get_day() == p[j + 1].member::get_day() && p[j].member::get_order() < p[j + 1].member::get_order()) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < number; ++i) {
		p[i].show_internation();
	}
	delete [100]p;
	return 0;
}