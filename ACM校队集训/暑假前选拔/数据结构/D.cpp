#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;

int arr[maxn],cnt;

void ins (int x);
void vec_sort(int l,int r,int x);
void del (int x);
int  find_x (int x);
int find_rank (int x);
int find_num (int x,int opt);

int main()
{
    int n,opt,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&opt,&x);
        switch (opt){
        case 1:
            ins(x);
            break;
        case 2:
            del(x);
            break;
        case 3:
            printf("%d\n",find_x(x));
            break;
        case 4:
            printf("%d\n",find_rank(x));
            break;
        default :{
            int ans=find_num(x,opt);
            if(ans) printf("%d\n",ans);
            break;
        }
        }
       // system("pause");
    }
    return 0;
}

void ins(int x){
    if(cnt>0){
        if(x>arr[cnt]){
            arr[++cnt]=x;
            return;
        }
        int idx=lower_bound(arr+1,arr+1+cnt,x)-arr;
        for(int i=++cnt;i>idx;--i) arr[i]=arr[i-1];
        arr[idx]=x;
        return ;
    }
    arr[++cnt]=x;
}
void del(int x){
    int i=1,j=cnt,mid;
    int idx=lower_bound(arr+1,arr+1+cnt,x)-arr;
    for(int i=idx;i<=cnt-1;++i) arr[i]=arr[i+1];
    arr[cnt--]=0;
}
int find_x(int x){
    return lower_bound(arr+1,arr+1+cnt,x)-arr;
}
int find_rank(int x){
    return arr[x];
}
int find_num(int x,int opt){
    int mid=0;
    if(opt==5){
        if(x<=arr[1]){
            printf("NOT FOUND\n");
            return 0;
        }
        if(x>arr[cnt]){
            return arr[cnt];
        }
        return arr[lower_bound(arr+1,arr+1+cnt,x)-arr-1];
    }
    if(opt==6){
        if(x>=arr[cnt]){
            printf("NOT FOUND\n");
            return 0;
        }
        if(x<arr[1]){
            return arr[1];
        }
        return arr[upper_bound(arr+1,arr+1+cnt,x)-arr];
    }
}
