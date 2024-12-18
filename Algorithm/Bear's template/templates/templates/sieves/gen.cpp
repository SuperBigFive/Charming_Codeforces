#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int, char** argv) {
    int n = atoi(argv[1]);
    ll m = atoll(argv[2]);
    mt19937_64 mt(time(0));
    uniform_int_distribution<ll> uid(1, m);
    cout << n << endl;
    for (int i = 1; i <= n; ++i)
        cout << uid(mt) << endl;
    return 0;
}