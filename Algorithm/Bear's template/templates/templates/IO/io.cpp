#include <bits/stdc++.h>
#include <cctype>
using namespace std;

const int N = 1000002;

namespace io {

const int S = 1<<24;
char s[S], *t, *p;

bool get() { t = s + fread(s, 1, S, stdin); p = s; return s != t; }
bool eof() { return p == t && !get(); }
char getc(int c = 1) { if (eof()) return -1; while (--c) ++p; return *p++; }
void skip() { while (!isgraph(getc())); p--;}

template<class T>
void readi(T& i) {
    skip(); i = 0; char ch = getc(); bool neg = (ch == '-');
    if (neg) ch = getc();
    for (; isdigit(ch); ch = getc()) i = 10 * i + (ch - '0');
    if (neg) i = -i;
}

int readl(char* s) {
    int n = 0; while ((*s++ = getc()) != '\n') ++n;
    return n;
}

}

using io::readi;

int main(void) {
    int n; readi(n);
    vector<int> lp(N, -1);
    vector<int> dp(N, 0);
    for(int i = 0; i != n; ++i) {
        int l, r; readi(l); readi(r);
        if (l > r) swap(l, r);
        lp[r] = max(lp[r], l);
    }
    int ans = 0;
    for (int i = 1; i != N; ++i) {
        dp[i] = dp[i - 1];
        if (lp[i] != -1)
            dp[i] = max(dp[i], dp[lp[i]] + 1);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}