#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int maxn=1e6+5;

ll n,k,cnt,tot;
ll money[maxn],goods[maxn],diff[maxn],nex[maxn],pre[maxn];
bool flag[maxn];

int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%lld",&money[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&goods[i]);
	}
	sort(money+1,money+1+n);
	sort(goods+1,goods+1+n);
	for(int i=1;i<=n;++i){
		pre[i]=i+1;
		nex[i]=i-1;
	}
	
/*	for(int i=1;i<=n;++i){
		printf("%d ",money[i]);
	}
	printf("\n");
	for(int i=1;i<=n;++i){
		printf("%d ",goods[i]);
	}
	printf("\n");
	
	for(int i=1;i<=n;++i){
		printf("%d's pre is:%d\n%d's nex is:%d\n",money[i],pre[i],money[i],nex[i]);
	}
	*/
	pre[0]=1;
	pre[n]=n;
	ll i,j,tail=n;
	ll sum=0;
	for(i=n;i>=1;--i){
		if(k<0){
			printf("NIE\n");
			return 0;
		}
		if(money[tail]<goods[i]){
			//cnt=pre[tail];
			/*int cnt2=1;
			while(money[cnt]>=goods[i-cnt2]&&cnt>0&&cnt2<i) {
				cnt=pre[cnt];
				++cnt2;
			}*/
			sum+=goods[i];
			--k;
			//++cnt;
			/*if(!cnt){
				ll temp=tail;
				tail=nex[tail];
				pre[tail]=pre[temp];
			}
			else{
				pre[nex[cnt]]=pre[cnt];
				nex[pre[cnt]]=nex[cnt];		
			}*/
			continue;
		}
		//bool flag=true;
		j=nex[tail];
		while(j){
			if(money[j]<goods[i]){
				while(flag[j]) ++j;
				while(money[j]<goods[i]) j=pre[j];
				//j=nex[j];
				if(j==tail) tail=nex[tail];
				sum+=money[j];
				flag[j]=true;
				pre[nex[j]]=pre[j];
				nex[pre[j]]=nex[j];
				diff[++tot]=money[j]-goods[i];
				//flag=false;
				break;
			}
			if(j>688) j=nex[j-666];
			else j=nex[j];
		}
		if(j) continue;
		j=pre[j];
		sum+=money[j];
		flag[j]=true;
		pre[nex[j]]=pre[j];
		nex[pre[j]]=nex[j];
		diff[++tot]=money[j]-goods[i];
	}
	sort(diff+1,diff+1+tot);
	while(k-->0&&tot){
		sum-=diff[tot--];
	}
	printf("%lld\n",sum);
	return 0;
}
