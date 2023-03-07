#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],pos[maxn];
char s[maxn];
int main()
{
	int n,t=0,k=0;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++){
		if(s[i]=='(')pos[k++]=i+1;
		else if(s[i]==')')a[++t]=i+1,a[++t]=pos[k-1],k--;
		else a[++t]=i+1;
	}
	for(int i=1;i<=t;i++)
	printf("%d ",a[i]);
	return 0;
}
