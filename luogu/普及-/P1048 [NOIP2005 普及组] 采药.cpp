#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int maxt=1e3+5;
const int maxm=1e2+5;

int t,m;
int ttime[maxm],val[maxm];
int dp[maxm][maxt];

int main(){
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;++i) scanf("%d%d",&ttime[i],&val[i]);
    memset(dp,0,sizeof dp);
    for(int i=1;i<=m;++i){
        for(int j=1;j<=t;++j){
            if(ttime[i]<=j){
                dp[i][j]=max(dp[i-1][j-ttime[i]]+val[i],dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    printf("%d\n",dp[m][t]);
    return 0;
}
