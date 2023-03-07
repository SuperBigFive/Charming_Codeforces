#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char s1[maxn],s2[maxn];
int main()
{
	int f=0,t;
	scanf("%s",s1);
	scanf("%s",s2);
	while(!isalpha(s2[0]))scanf("%s",s2);
	for(t=0;isalpha(s1[t])&&!f;t++)
	if(s1[t]>s2[t])f=1;
	else if(s1[t]<s2[t])f=-1;
	if(!f){
		if(strlen(s1)>strlen(s2))f=1;
		else if(strlen(s1)<strlen(s2))f=-1;
		else {
			for(int i=t;s1[i]!='\0'&&!f;i++)
			if(s1[i]>s2[i])f=1;
			else if(s1[i]<s2[i])f=-1;
		}
	}
	if(f==1)printf(">");
	else if(f==-1)printf("<");
	else printf("=");
	return 0;
}