n1, n2, m = map (int, input ().split ())
G = list ([] for i in range (n1 + n2))
for i in range (m) :
    u, v = map (int, input ().split ())
    u -= 1; v -= 1
    G[u].append (v)
    G[v].append (u)
dis1 = [0] * n1; dis2 = [0] * (n1 + n2)
q = [0] * n1; vis = [0] * n1; cnt = 1; vis[0] = 1
for i in range (n1) :
    u = q[i]
    for v in G[u] :
        if vis[v] : continue
        else :
            vis[v] = True
            q[cnt] = v
            cnt += 1
            dis1[v] = dis1[u] + 1
q = [0] * n2; q[0] = n1 + n2 - 1
vis = [0] * (n1 + n2); cnt = 1; vis[n1 + n2 - 1] = 1
for i in range (n2) :
    u = q[i]
    for v in G[u] :
        if vis[v] : continue
        else :
            vis[v] = True
            q[cnt] = v
            cnt += 1
            dis2[v] = dis2[u] + 1
print (max (dis1) + max (dis2) + 1)
