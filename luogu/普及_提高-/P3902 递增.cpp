#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+15;

int arr[maxn],arr2[maxn];
int dp[maxn];

int main(){
    int n,w;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
        //if(arr[i]==arr2[ans]) continue;
        if(arr[i]<=arr2[ans]){
            int tmp=lower_bound(arr2+1,arr2+ans+1,arr[i])-arr2;
            arr2[tmp]=arr[i];
            continue;
        }
        arr2[++ans]=arr[i];
    }
    printf("%d\n",n-ans);
    return 0;
}
