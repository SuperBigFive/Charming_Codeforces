#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int* a, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[i]) swap(a[i], a[j]);
}

void bfprt(int* a, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i += 5) {
        int l = i, r = min(i + 5, n);
        insertion_sort(a + l, r - l);
        swap(a[i / 5], a[(l + r) / 2]);
        cnt++;
    }
    if (cnt != 1) bfprt(a, cnt);
}

void kth_element(int* a, int n, int k) {
    bfprt(a, n);
    int p = 1;
    for (int i = 1; i < n; ++i)
        if (a[i] < a[0])
            swap(a[i], a[p])
             

    
}

int main(void) {


    partition

    return 0;
}