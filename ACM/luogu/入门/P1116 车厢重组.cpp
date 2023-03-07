#include<iostream>
using namespace std;
int main()
{
	int N,temp,time=0;
	cin >> N;
	int *p=new int [N];
	for (int i = 0; i < N; ++i)
		cin >> p[i];
	for (int i =N; i >= 1; --i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (p[j] == i)
			{
				time += i-j-1;
				for (; j < i-1; ++j)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
		}
	} 
	delete [N]p;
	cout << time << endl;
	return 0;
}