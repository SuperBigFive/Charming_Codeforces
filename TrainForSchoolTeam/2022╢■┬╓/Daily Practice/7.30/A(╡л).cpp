#include<bits/stdc++.h>
using namespace std;
int a[15][4],dig[15][10],rep[15][2];
int main()
{
	int n,cnt=0,ans[4];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(!isdigit(ch))ch=getchar();
		for(int t=0;t<4;t++)
		a[i][t]=ch-'0',dig[i][a[i][t]]=1,ch=getchar();
		scanf("%d%d",&rep[i][0],&rep[i][1]);
	}
	for(int i=0;i<10&&cnt<2;i++)
	for(int j=0;j<10&&cnt<2;j++){
		if(j==i)continue;
		for(int k=0;k<10&&cnt<2;k++){
			if(k==j||k==i)continue;
			for(int t=0;t<10&&cnt<2;t++){
				if(t==k||t==j||t==i)continue;
				int mk=1;
				for(int p=1;p<=n;p++){
					int bul=0,cow=0;
					if(a[p][0]==i)bul++;
					else if(dig[p][i])cow++;
					if(a[p][1]==j)bul++;
					else if(dig[p][j])cow++;
					if(a[p][2]==k)bul++;
					else if(dig[p][k])cow++;
					if(a[p][3]==t)bul++;
					else if(dig[p][t])cow++;
					if(bul!=rep[p][0]||cow!=rep[p][1]){mk=0;break;}
				}
				if(mk){
					cnt++;
					if(cnt==1)ans[0]=i,ans[1]=j,ans[2]=k,ans[3]=t;
					else break;
				}
			}
		}
	}
	switch(cnt){
		case 0:printf("Incorrect data");break;
		case 1:printf("%d%d%d%d",ans[0],ans[1],ans[2],ans[3]);break;
		case 2:printf("Need more data");break;
	}
	return 0;
}