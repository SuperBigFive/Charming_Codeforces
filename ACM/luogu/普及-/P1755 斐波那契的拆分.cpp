#include<iostream>
using namespace std;
typedef struct Note {
	int value;
	Note* next = NULL;
}Note;
Note head;
Note* ptr=&head;
int n[91];

void fibo(int& number,int& count);

int main()
{
	int N,max=0,num,count=0;
	cin >> N;
	int* p_number = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> p_number[i];
		if (p_number[i] > max)
			max = p_number[i];
	}

	ptr->value = 1;
	Note* construct=new Note;
	construct->value = 1;
	for (; ptr->value+construct->value<=max; ) {
		ptr->next = construct;
		construct = new Note;
		construct->value = ptr->value + ptr->next->value;
		ptr = ptr->next;
	}
	ptr->next = construct;
	for (int i = 0; i < N; ++i) {
		cout << p_number[i] << "=";
		for (num=-1;;) {
			fibo(p_number[i],count);
			++num;
			if (p_number[i] == 0) {
				break;
			}
		}
		count = 0;
		for (; num >= 0; --num) {
			cout << n[num];
			if (!num)
				cout << endl;
			else
				cout << "+";
		}
	}
	delete [N]p_number;
	ptr = head.next;
	for (Note *p=ptr; p->next != NULL; ){
		p = p->next;
		delete ptr;
		ptr = p;
	}
	return 0;
}

void fibo(int& number,int& count) {
	for (ptr = &head; ptr->value <= number; ptr = ptr->next) {
		if (ptr->next==NULL||ptr->next->value > number) {
			n[count]=ptr->value;
			++count;
			number -= ptr->value;
			break;
		}
	}
}