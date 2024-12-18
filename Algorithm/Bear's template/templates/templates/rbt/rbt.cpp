#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int ch[3][N], *const ls = ch[0], *const rs = ch[1], *const fa = ch[2];
int c[N];

bool isr(int x) { return fa[fa[x]] == x; }
int id(int x) { return isr(x) ? 2 : rs[fa[x]] == x; }

void rot(int x) {}

void erase(int x) {
    int y;
    if (ls[x] && rs[x]) {
        y = ls[x];
        while (rs[y]) y = rs[y];
        ch[id(x)][fa[x]] = fa[rs[x]] = fa[ls[x]] = y;
        ch[id(y)][fa[y]] = x;
        if (ls[y]) fa[ls[y]] = x;
        swap(ls[y], ls[x]);
        swap(rs[y], rs[x]);
        swap(fa[y], fa[x]);
    }
    //  !ls[x] || !rs[x]
    if (y = ls[x] | rs[x]) rot(y), c[y] = 0, c[x] = 1;
    //  !ls[x] && !rs[x]
    ch[id(x)][fa[x]] = 0;
    while (!isr(x)) {
        int y = fa[x], o = id(x), w = ch[!o][y], u = ch[o][w], v = ch[!o][w];
        if (c[w]) { 
            rot(w);
            c[u] = 1;
            c[w] = 0;
            break;
        }
        if (!c[u] && !c[v]) {
            c[w] = 1;
            if (c[y]) { c[y] = 0; break; }
            else x = y;
        }
        else {
            if (!c[v]) {
                rot(u);
                v = w; c[v] = 1;
                w = u; c[w] = 0;
            }
            rot(w);
            c[w] = c[y];
            c[y] = 1;
            c[v] = 0;
            break;
        }
    }    
}

int main(void) {




    return 0;
}