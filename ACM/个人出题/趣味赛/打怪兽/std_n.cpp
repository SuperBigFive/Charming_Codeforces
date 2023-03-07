#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,cnt1=0,cnt2=0,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		sum+=x;
		if(x%2)cnt1++;
	}
	cnt2=(sum-cnt1)/2;
	if(cnt1==cnt2)printf("%d",cnt1);
	else if(cnt1>cnt2)printf("%d",(cnt1+cnt2)/2+((cnt1+cnt2)%2>0));
	else {
		int x=(cnt2-cnt1)/3;
		printf("%d",max(cnt1+x*2,cnt2-x));
	}
	return 0;
}