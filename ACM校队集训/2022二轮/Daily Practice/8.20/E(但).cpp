#include<bits/stdc++.h>
using namespace std;
void query(int u){
	printf("%d\n",u);
	fflush(stdout);
}
void ans(int u){
	printf("! %d\n",u);
	fflush(stdout);
}
int main()
{
	int n,dis;
	scanf("%d",&n);
	if(n==1)ans(1);
	else {
		int u=1;
		query(u);
		scanf("%d",&dis);
		while(dis){
			u=u<<1;
			query(u);
			int ndis;
			scanf("%d",&ndis);
			if(ndis!=dis-1)u++;
			dis--;
		}
		ans(u);
	}
	return 0;
}