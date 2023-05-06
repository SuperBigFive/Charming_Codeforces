n = int (input ()); adj = [[] for i in range (n + 5)]
for i in range (n - 1) :
  u, v = map (int, input ().split ())
  adj[u].append (v)
  adj[v].append (u)

q = [0] * (n + 5); vis = [0] * (n + 5); ans = [0] * (n + 5)
head = 1; tail = 0; vis[n] = 1
tail += 1; q[tail] = n
while head <= tail :
  u = q[head]; head += 1
  for v in adj[u] :
    if vis[v] : continue
    vis[v] = 1; ans[v] = u;
    tail += 1; q[tail] = v
for i in range (1, n) : print (ans[i], end = " ")
print ()
