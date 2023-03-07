#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
const int maxn=510;
const int maxk=210;
const int maxt=1.5e5+15;
const int mod=10000;

int n,m,start,finish,k;
int i, j, p;
ll T,span,T_;
int scale[maxk];
int fish[maxk][51];
int dp[maxt][51];
int dp2[maxn][maxn];
int temp_dp2[maxt][51];
vector <int> node[maxn];
bool novis[maxn];
bool novis0[maxn];
struct Matr{
	int mat[51][51];
}matr1, matr2, temp, matr3, A[12];

Matr mult(Matr x,Matr y)
{
       for (i = 0; i < n; ++i)
       for (j = 0; j < n; ++j)
       temp.mat[i][j] = 0;
       for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
           {
               for(p=0;p<n;p++)
               {
                    temp.mat[i][j]=(temp.mat[i][j]+x.mat[i][p]*y.mat[p][j])%mod;
               }
           }
       }
       return temp;
}
void calc(int n)
{	
	while(n){
		if(n & 1)
			matr2 = mult (matr2, matr1);
		n >>=1;
		matr1 = mult (matr1, matr1);
	}
}
int main(){
	bool flag=false;
	scanf("%d%d%d%d%lld",&n,&m,&start,&finish,&T);
	int u,v;
	for(i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		node[u].push_back(v);
		node[v].push_back(u);
	}
	
	cin >> k;
    int t,pos;
    for(i = 1;i <= k;i++){
        cin >> t;
        for(j = 0; j < t;j++){
            cin>>pos;
            for(int pos2 = j; pos2 < 12; pos2 +=t){
                fish[pos2][pos] = 1;
            }
        }
    }
	/*scanf("%d",&k);
	for(i=1;i<=k;++i){
		scanf("%d",&scale[i]);
		for(j=0;j<scale[i];++j){
			scanf("%d",&fish[i][j]);
		}
	}*/
	for (p = 0; p <n; ++p) {
		memset (dp, 0 ,sizeof dp);
		dp[0][p]=1;
	    for(i=1;i<=11;++i){
	        memset(novis,false,sizeof novis);
	        for(j=0;j<=n;++j){
	        	if (fish[i][j]) novis[j] = true;
	            //novis[fish[j][i%scale[j]]]=true;
	        }
	        for(j=0;j<n;++j){
	            if(novis[j]){
	                dp[i][j]=0;
	                continue;
	            }
	            dp[i][j]=0;
	            for(int p=0;p<node[j].size();++p){
	                dp[i][j]=(dp[i][j]+dp[i-1][node[j][p]])%mod;
	            }
	        }
	    }
	    for (i = 0; i < n; ++i) {
	    	matr1.mat[p][i] = dp[11][i];
		}
	}
	
	/*for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			cout << matr1.mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	for(int tt=0;tt<12;tt++){
        for(i=0;i<n;i++){
            for(j=0;j<node[i].size();++j){
                A[tt].mat[i][node[i][j]] = !fish[tt][node[i][j]];
            }
        }
    }
	matr1 = mult (matr1, A[0]);
    int times = T/12;
    int t_= T - times*12;
    for (i = 0; i < n; ++i) matr2.mat[i][i] = 1;
    calc (times);
    
    /*for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		cout << A[3].mat[i][j] << " ";
		}
		cout << endl;
	}*/
	//matr2 = mult (matr2, A[0]);
    for(int i = 1 ;i <= t_; i++){
    	matr2 = mult (matr2, A[i]);
    }
    cout << matr2.mat[start][finish] << endl;
	
    //printf("%d\n",dp[T][finish]%mod);
    return 0;
}

