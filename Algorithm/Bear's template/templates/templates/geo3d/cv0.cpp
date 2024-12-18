#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct vec { ll x, y, z; };
vec operator+(vec v1, vec v2) { return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }; }
vec operator-(vec v1, vec v2) { return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z }; }
ll operator*(vec v1, vec v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
vec operator^(vec v1, vec v2) {
	return { v1.y * v2.z - v1.z * v2.y,
		     v1.z * v2.x - v1.x * v2.z,
		     v1.x * v2.y - v1.y * v2.x };
}

const int N = 2001;

vec p[N]; int n;
int l[N][N];

typedef pair<int, int> pii;

pii get_first_edge() {
    int u = 0;
    for (int i = 1; i < n; ++i)
        if (tie(p[i].x,p[i].y,p[i].z)<tie(p[u].x,p[u].y,p[u].z)) u = i;
    int v = u ? 0 : 1;
    for (int i = 0; i < n; ++i) {
        if (u == i || v == i) continue;
        vec v1 = p[v] - p[u], v2 = p[i] - p[u], v3 = v2 ^ v1;
        if (v3.z>0||(v3.z==0&&(v3.y<0||(v3.y==0&&(v3.x>0||v2*v2>v1*v1))))) v = i;
    }
    return { u, v };
}

pii get_next_edge(int u, int v) {
    int w = -1;
    for (int i = 0; i < n; ++i) {
        if (u == i || v == i) continue;
        if (w==-1||((p[i]-p[v])^(p[u]-p[v]))*(p[w]-p[v])<0) w = i;
    }
    l[u][v] = w;
    return { v, w };
}

void build() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            l[i][j] = -1;
    queue<pii> q; q.push(get_first_edge()); 
    while (!q.empty()) {
        int u, v; tie(u, v) = q.front(); q.pop();
        if (l[u][v] == -1) q.push(get_next_edge(u, v));
        if (l[v][u] == -1) q.push(get_next_edge(v, u));
    }
}