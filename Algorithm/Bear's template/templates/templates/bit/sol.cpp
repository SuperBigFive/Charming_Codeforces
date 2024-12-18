#include <bits/stdc++.h>
using namespace std;

int calc(int k, int m) {
    int n = 1 << k;
    vector<int> c(n, 0);
    for (int i = 0; i != (1 << n); ++i) {
        int x = 0;
        if (__builtin_popcount(i) != m) continue;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                x ^= j;
        c[x]++;   
    }
    for (int i = 2; i < n; ++i)
        assert(c[i] == c[i - 1]);
    return c[1];
}
int main(void) {
    int k; scanf("%d", &k);
    for (int i = 1; i < (1 << k); ++i)
        printf("%d\n", calc(k, i));
    
    return 0;
}