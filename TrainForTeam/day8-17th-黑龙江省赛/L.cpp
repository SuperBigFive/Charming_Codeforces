#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
char s[maxn*2],t[3][maxn];
int nxt[maxn],b[maxn];
void get_nxt(int n,int k){
	nxt[0]=-1;
	for(int i=1;i<n;i++){
		nxt[i]=nxt[i-1]+1;
		while(t[k][nxt[i]]!=t[k][i]&&nxt[i]>0)nxt[i]=nxt[nxt[i]-1]+1;
		if(!nxt[i]&&t[k][nxt[i]]!=t[k][i])nxt[i]=-1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		scanf("%s",t[0]);
		int n=strlen(s),l1,l2;
		scanf("%d%d",&l1,&l2);
		int l=abs(l1-l2),f=0;
		for(int i=n;i<n*2;i++)
		s[i]=s[i-n];
		for(int i=0;i<l1;i++)
		t[1][i]=t[0][l1-i-1];
		for(int i=l1;i<n;i++)
		t[1][i]=t[0][n+l1-i-1];
		for(int i=0;i<l2;i++)
		t[2][i]=t[0][l2-i-1];
		for(int i=l2;i<n;i++)
		t[2][i]=t[0][n+l2-i-1];
		for(int i=0;i<n;i++)
		b[i]=0;
		for(int i=l%n;!b[i];i=(i+l)%n)
		b[i]=1;
		for(int k=0;k<3&&!f;k++){
			get_nxt(n,k);
			for(int i=0,j=0;i<n*2;i++,j++){
				while(j>0&&s[i]!=t[k][j])j=nxt[j-1]+1;
				if(!j&&s[i]!=t[k][j])j=-1;
				if(j==n-1){
					f=b[i-n+1];
					if(f)break;
					else j=nxt[j];
				}
			}
		}
		if(f)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
