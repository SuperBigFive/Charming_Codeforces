#include<iostream>
#include<math.h>
using namespace std;
const int maxn=1e2+5;

int arr[maxn];
int dp1[maxn],dp2[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
    for(int i=1;i<=n;++i){
        dp1[i]=1;
        for(int j=1;j<i;++j){
            if(arr[j]<arr[i]) dp1[i]=max(dp1[i],dp1[j]+1);
        }
    }
    for(int i=n;i>=1;--i){
        dp2[i]=1;
        for(int j=n;j>i;--j){
            if(arr[j]<arr[i]) dp2[i]=max(dp2[i],dp2[j]+1);
        }
    }
    int ans=101;
    for(int i=1;i<=n;++i){
        ans=min(ans,n-dp1[i]-dp2[i]+1);
    }
    printf("%d\n",ans);
    return 0;
}
