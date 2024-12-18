#include "dinic.hpp"

namespace bounded_flow {

using dinic::n;
using dinic::g;
using dinic::addv;
using dinic::adde;

ll df[N];
void adde_c(int u, int v, ll cl, ll cr) {
    adde(u, v, cr - cl);
    df[u] -= cl;
    df[v] += cl;
}

bool feasible_circulation() {
    int s = addv(1), t = addv(1);
    ll sf = 0;
    for (int i = 0; i < n - 2; ++i) {
        if (!df[i]) continue;
        if (df[i] > 0) adde(s, i, df[i]), sf += df[i];
        else adde(i, t, -df[i]);
    }
    ll res = dinic::maxflow(s, t, sf); n -= 2;
    for (int i = 0; i < n; ++i)
        while (!g[i].empty() && g[i].back().v >= n) g[i].pop_back();
    return res == sf;
}

ll feasible_flow(int s, int t) {
    adde(t, s, inf);
    if (!feasible_circulation()) return -1;
    ll sf = g[s].back().c;
    g[s].pop_back(); g[t].pop_back();
    return sf;    
}

ll maxflow(int s, int t, ll mf) {
    ll res = feasible_flow(s, t);
    if (res == -1) return -1;
    return dinic::maxflow(s, t, mf - res) + res;
}

ll minflow(int s, int t) {
    ll res = feasible_flow(s, t);
    if (res == -1) return -1;
    return res - dinic::maxflow(t, s, inf);
}
    
}

using bounded_flow::adde_c;
using bounded_flow::feasible_circulation;
using bounded_flow::feasible_flow;
using bounded_flow::maxflow;
using bounded_flow::minflow;
