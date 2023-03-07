#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		ll k,x,y,mul=1;
		scanf("%lld%lld%lld",&k,&x,&y);
		int t=0;
		a[t]=x;
		while((double)mul<(double)x/(k+1))mul*=k+1;
		while(mul>0){
			if((x-mul)%k)a[++t]=x=(x-mul)/k+1;
			else a[++t]=x=(x-mul)/k;
			while(mul>=x)mul/=k+1;
		}
		mul=1;
		while((double)mul<(double)y/(k+1))mul*=k+1;
		for(int i=0;i<=t;){
			while(a[i]>y)i++;
			if(a[i]==y){printf("%lld\n",y);break;}
			y=(y-mul)%k?(y-mul)/k+1:(y-mul)/k;
			while(mul>=y)mul/=k+1;
		}
	}
	return 0;
}
	