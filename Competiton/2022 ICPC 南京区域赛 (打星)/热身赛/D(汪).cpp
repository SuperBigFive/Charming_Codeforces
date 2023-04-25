#include<bits/stdc++.h>
#define N 510
using namespace std;
int n,a,b;
char op[3];
int main()
{
    cin>>n>>a>>b;
    if(a-1<=n-a && b-1<=n-b)
    {
        for(int i=1;i<=n-1;i++)
            printf("U");
        for(int i=1;i<=n-1;i++)
            printf("L");
        for(int i=1;i<=a-1;i++)
            printf("D");
        for(int i=1;i<=b-1;i++)
            printf("R");
    }
    else if(a-1<=n-a && b-1>n-b)
    {
        for(int i=1;i<=n-1;i++)
            printf("U");
        for(int i=1;i<=n-1;i++)
            printf("R");
        for(int i=1;i<=a-1;i++)
            printf("D");
        for(int i=1;i<=n-b;i++)
            printf("L");
    }
    else if(a-1>n-a && b-1<=n-b)
    {
        for(int i=1;i<=n-1;i++)
            printf("D");
        for(int i=1;i<=n-1;i++)
            printf("L");
        for(int i=1;i<=n-a;i++)
            printf("U");
        for(int i=1;i<=b-1;i++)
            printf("R");
    }
    else if(a-1>n-a && b-1>n-b)
    {
        for(int i=1;i<=n-1;i++)
            printf("D");
        for(int i=1;i<=n-1;i++)
            printf("R");
        for(int i=1;i<=n-a;i++)
            printf("U");
        for(int i=1;i<=n-b;i++)
            printf("L");
    }
}
