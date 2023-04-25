#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;

ll shop[maxn];
ll sum[maxn];
priority_queue <ll,vector<ll>,greater<ll> > pq;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		ll x;
		if(t<10){
			scanf("%d%lld",&n,&x);
			for(int i=1;i<=n;++i) scanf("%lld",&shop[i]);
			sort(shop+1,shop+1+n);
			sum[1]=shop[1];
			for(int i=2;i<=n;++i) sum[i]=sum[i-1]+shop[i];
			int day=2;
			int start=upper_bound(sum+1,sum+1+n,x)-sum-1;
			ll ans=start;
			int pos=start;
			while(shop[1]+day-1<=x){
				while(x<sum[pos]+pos*(day-1)) --pos;
				ans+=pos;
				++day;
			}
			printf("%lld\n",ans); 
			continue;
		} 
		scanf("%d%lld",&n,&x);
		while(!pq.empty()) pq.pop();
		for(int i=1;i<=n;++i){
			scanf("%lld",&shop[i]);
			if(shop[i]<=x) pq.push(shop[i]);
		}
		if(pq.empty()){
			printf("0\n");
			continue;
		}
		ll tmp=pq.top();
		pq.pop();
		int tot=1;
		sum[1]=tmp;
		while(!pq.empty()){
			tmp=pq.top();
			pq.pop();
			sum[tot+1]=sum[tot++]+tmp;
		}
		int day=2;
		int start=upper_bound(sum+1,sum+1+n,x)-sum-1;
		ll ans=(ll)start;
		int pos=start;
		while(sum[1]+day-1<=x){
			while(x<sum[pos]+pos*(day-1)) --pos;
			ans+=(ll)pos;
			++day;
		}
		printf("%lld\n",ans); 
	}
	return 0;
} 
