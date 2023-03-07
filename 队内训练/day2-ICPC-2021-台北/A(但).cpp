#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y,n;
		scanf("%d%d%d",&x,&y,&n);
		if(n%(x+y)>x)printf("%d\n",(n/(x+y)+1)*x*3);
		else printf("%d\n",(n/(x+y)*x+n%(x+y))*3);
	}
	return 0;
}