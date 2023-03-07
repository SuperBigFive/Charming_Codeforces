#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    Student(string name = "", int age = 0, float score = 0.0f);  //普通构造函数
    Student(const Student& stu);  //拷贝构造函数（声明）
public:
    void display();
private:
    string m_name;
    int m_age;
    float m_score;
};
Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) { }
//拷贝构造函数（定义）
Student::Student(const Student& stu) {
    this->m_name = stu.m_name;
    this->m_age = stu.m_age;
    this->m_score = stu.m_score;

    cout << "Copy constructor was called." << endl;
}
void Student::display() {
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
}
int main() {
    Student stu1("小明", 16, 90.5);
    Student stu2 = stu1;  //调用拷贝构造函数
    Student stu3(stu1);  //调用拷贝构造函数
    stu1.display();
    stu2.display();
    stu3.display();

    return 0;
}