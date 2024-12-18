#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
bool ip[N]; vector<int> ps;
void sieve() {
    fill_n(ip, N, 1); ip[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (ip[i]) ps.push_back(i);
        for (int j : ps) {
            if (i * j >= N) break;
            ip[i * j] = 0;
            if (i % j == 0) break;
        }
    }
}
