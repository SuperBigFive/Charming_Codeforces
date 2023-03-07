import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)
n, m = map (int, input ().split ())
adj = list ([] for i in range (n + 5))
for i in range (m) :
  u, v = map (int, input ().split ())
  adj[u].append (v)
vis = list (); f = [0] * (n + 5)

def get_f (u) :
  vis[u] = True
  for v in adj[u] :
    if vis[v] : continue
    else : get_f (v)

res = 0
for i in range (1, n + 1) :
  vis = [0] * (n + 5); get_f (i)
  for j in range (1, n + 5) :
    if vis[j] and i != j: f[i] += 1
for i in range (1, n + 1) :
  res += f[i] - len (adj[i])
print (res)
