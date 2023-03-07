#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e5+15;

ll arr[maxn],arr2[maxn];
ll dp[maxn];

int main(){
    ll n,w;
    scanf("%lld%lld",&n,&w);
    if(n>1000){
        int ans=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            arr[i]-=i;
            //if(arr[i]==arr2[ans]) continue;
            if(arr[i]<arr2[ans]){
                int tmp=lower_bound(arr2+1,arr2+ans+1,arr[i])-arr2;
                arr2[tmp]=arr[i];
                continue;
            }
            arr2[++ans]=arr[i];
        }
        printf("%lld\n",(n-ans)*w);
        return 0;
    }
    else{
        for(int i=1;i<=n;++i) scanf("%d",&arr[i]),arr[i]+=n-i;
        ll mmax=0;
        for(int i=1;i<=n;++i){
            dp[i]=1;
            for(int j=1;j<i;++j){
                if(arr[j]<=arr[i]) dp[i]=max(dp[i],dp[j]+1);
            }
            mmax=max(mmax,dp[i]);
        }
        printf("%lld\n",(n-mmax)*w);
        return 0;
    }
}
