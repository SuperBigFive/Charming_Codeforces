#include<iostream>
using namespace std;
int main()
{
	int N, M, X, Y, time[100] = { 0 }, LastTime[100] = { 0 };
	cin >> N >> M >> X >> Y;
	int BoomScale1[100], BoomScale2[100], BoomScale3[100], BoomScale4[100], Emphasis1[100], Emphasis2[100];
	for (int i = 0; i < X; ++i)
	{
		cin >> BoomScale1[i] >> BoomScale2[i] >> BoomScale3[i] >> BoomScale4[i];
	}
	for (int i = 0; i < Y; ++i)
	{
		cin >> Emphasis1[i] >> Emphasis2[i];
	}
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			if (Emphasis1[i] >=BoomScale1[j] && Emphasis1[i]<=BoomScale3[j] && Emphasis2[i]>=BoomScale2[j] && Emphasis2[i] <= BoomScale4[j])
			{
				++time[i];
				LastTime[i] = j+1;
			}
		}
	}
	bool flag;
	for (int i = 0; i < Y; ++i)
	{
		flag = time[i] > 0;
		if (flag)
		{
			cout << "Y " << time[i] << " " << LastTime[i]<<endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}
	return 0;
}