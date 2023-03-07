#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5e4+15;

int n,t,aff_t,tot=0;
int stack[maxn],pos[maxn];
int dp[maxn];
int pmove[maxn];
int Time_cost[maxn];
struct Ticket{
	int dis;
	int price;
	bool operator<(const Ticket tmp)const{
        return price<tmp.price;
    }
}tk[maxn];

bool Dp(int move);

int main(){
	scanf("%d%d",&n,&t);
	aff_t=t-(n-1);
	for(int i=1;i<n;++i){
		int p;
		scanf("%d",&p);
		if(p<=tk[tot].price){
			Ticket tmp;
			tmp.dis=i;
			tmp.price=p;
			tot=lower_bound(tk+1,tk+1+tot,tmp)-tk;
			tk[tot].price=p;
			tk[tot].dis=i;
			continue;
		}
		tk[++tot].price=p;
		tk[tot].dis=i;
	}
	for(int i=2;i<=n-1;++i) 
		scanf("%d",&Time_cost[i]);
	for(int i=1;i<=tot;++i){
		//int t=clock();
		if(Dp(tk[i].dis)){
			printf("%d\n",tk[i].price);
			return 0;
		}
		//printf("%d\n",clock()-t); 
	}
} 

bool Dp(int move){
	int head=1,tail=0;
	for(int i=2;i<=move+1;++i){
		dp[i]=Time_cost[i];
		while(head<=tail&&stack[tail]>Time_cost[i]) tail--;
		++tail;
		stack[tail]=Time_cost[i];
		pos[tail]=i;
		while(pos[head]<=i-move&&head<tail) head++;
	} 
	for(int i=move+2;i<=n;++i){
		dp[i]=stack[head]+Time_cost[i];
		while(head<=tail&&stack[tail]>dp[i]) tail--;
			stack[++tail]=dp[i];
			pos[tail]=i;
		while(pos[head]<=i-move&&head<tail) head++;
		
		/*for(int j=1;j<=move;++j){
			dp[i]=min(dp[i],dp[i-j]+Time_cost[i]);
		}*/
	}
	if(dp[n]>aff_t) return false;
	//printf("%d\n",dp[n]);
	return true;
}
