#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=2e5+15;

int suml[maxn];
int sumr[maxn];
char str[maxn];
int pos1[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str+1);
		int tot=0;
		bool keyy=false;
		int tmp0=0,cost0=0;
		for(int i=1;str[i]!='\0';++i){
			if(str[i]=='0') tmp0++;
			else {
				pos1[++tot]=i;
				if(!keyy){
					tmp0=0;
					keyy=true;
					continue;
				}
				cost0+=tmp0,tmp0=0;
			}
		}
		for(int i=1;i<tot;++i){
			suml[i]=suml[i-1]+pos1[i+1]-pos1[i]-1;
			sumr[i]=sumr[i-1]+pos1[tot-i+1]-pos1[tot-i]-1;
		}
		int ans=cost0;
		int tmp,pl,pr;
		for(pl=0;pl<tot;++pl){
			pr=lower_bound(sumr+1,sumr+1+tot,(cost0-suml[pl])/2)-sumr-1;
			tmp=max(cost0-suml[pl]-sumr[pr],pl+pr);
			ans=min(ans,tmp);
			bool vis=false;
			while(cost0-sumr[pr]-suml[pl]<pl+pr&&pr>0){
				--pr;
				tmp=max(cost0-sumr[pr]-suml[pl],pl+pr);
				ans=min(ans,tmp);	
				vis=true;
			} 
			while(cost0-sumr[pr]-suml[pl]>pl+pr&&pr<tot&&!vis){
				++pr;
				tmp=max(cost0-sumr[pr]-suml[pl],pl+pr);
				ans=min(ans,tmp);	
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}
