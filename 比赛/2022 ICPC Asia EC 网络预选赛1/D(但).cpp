#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mi[50];
int isok(ll x){
	int f=1,cnt1=0,cnt0=0;
	while(x){
		if(f&&x%2==0)cnt0++;
		if(x%2==1)cnt1++,f=0;
		x/=2;
	}
	if(cnt1==cnt0)return 100;
	if(cnt1>cnt0)return -1;
	return cnt1;
}
int main()
{
	int T;
	mi[0]=1;
	for(int i=1;i<=33;i++)
	mi[i]=2*mi[i-1];
	scanf("%d",&T);
	while(T--){
		ll l,r,f=0;
		scanf("%lld%lld",&l,&r);
		for(ll i=l;i<=r;){
			int t=isok(i);
			if(t==100){
				printf("%lld\n",i);
				f=1;
				break;
			}
			if(t<0)i+=i&(-i);
			else i+=mi[t];
		}
		if(!f)printf("-1\n");
	}
	return 0;
}