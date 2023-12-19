n = int (input ())
G = [[] for i in range (n)]
du = [0] * n; fa = [-1] * n; siz = [1] * n
for i in range (n - 1) :
    u, v = map (int, input ().split ())
    u -= 1; v -= 1
    G[u].append (v); G[v].append (u)
    du[u] += 1; du[v] += 1
q = [0] * n
head = 0; tail = 1
vis = [0] * n
while head < tail :
    u = q[head]
    head += 1
    vis[u] = 1
    for v in G[u] :
        if vis[v] : 
            continue
        else :
            q[tail] = v
            tail += 1
            fa[v] = u

for i in range (n - 1, -1, -1) :
    u = q[i]
    if fa[u] >= 0 :
        siz[fa[u]] += siz[u]
mx = 0
for v in G[u] :
    mx = max (mx, siz[v])
print (n - mx)