#include<iostream>
using namespace std; 
int arr[1000000];
int flag1,flag2;

int main(){
	int n;
	scanf("%d",&n);
	int min1=99999999,min2=99999999;
	int loc1,loc2;
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
		if(min1>arr[i]) loc1=i,min1=arr[i];
	}
	for(int i=1;i<=n;++i){
		if(i!=loc1&&min2>arr[i]) loc2=i,min2=arr[i];
	}
	flag1=min1%2;
	flag2=min2%2;
	int dis=loc2-loc1;
	int ans;
	if(dis<0) dis=-dis;
	if(dis==1){
		ans+=min2/2+flag2;
		if(min1>min2/2+flag2){
			ans+=(min1-min2/2-flag2)/2+flag1;
		}
	}
	if(dis>2) ans=min1/2+min2/2+flag1+flag2;
	if(dis==2){
		int cost1=min1+(min2-min1)/2+(min2-min1)%2;
		int cost2=min2/2+flag2+min1/2+flag1;
		if(cost1<cost2) ans=cost1;
		else ans=cost2;
	}
	for(int i=1;i<n;++i){
		int diff=arr[i]-arr[i+1];
		if(diff<0) diff=-diff;
		int sum=arr[i]+arr[i+1];
		int mn=arr[i]<arr[i+1]?arr[i]:arr[i+1];
		int times=sum/3+1;
		if(!(sum%3)) --times;
		if(mn>=times) ans=ans<times?ans:times;
	}
	for(int i=2;i<n;++i){
		int mn=arr[i-1]>arr[i+1]?arr[i-1]:arr[i+1];
		ans=ans<mn?ans:mn;
	}
	printf("%d",ans);
	return 0;
}
