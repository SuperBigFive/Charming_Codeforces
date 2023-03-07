#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=5010;
int s[maxn];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='A'&&ch!='C'&&ch!='G'&&ch!='T')ch=getchar();
		switch(ch){
			case 'A':s[i]=0;break;
			case 'C':s[i]=1;break;
			case 'G':s[i]=2;break;
			case 'T':s[i]=3;break;
		}
	}
	for(int i=1;i<=n;i++){
		int cnt[4]={0,0,0,0};
		for(int j=i;j<=n;j++){
			cnt[s[j]]++;
			if(cnt[0]==cnt[3]&&cnt[1]==cnt[2])ans++;
		}
	}
	printf("%d",ans);
	return 0;
}