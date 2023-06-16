N = 10 ** 5 + 5
prim = list (); vis = [0] * (N)
for i in range (2, N) :
  if vis[i] == 0 : prim.append (i)
  for j in prim :
    if i * j >= N : break
    vis[i * j] = 1
    if i % j == 0 : break

n = int (input ())
G = list (list () for i in range (n + 5))
vis = [0] * (n + 5); ans = [0] * (n + 5)
for i in range (2, n + 1) :
  for j in range (2, n + 1) :
    if i * j > n : break
    ans[i] += j
    G[i].append ((i * j, j))
    G[i * j].append ((i, j))
#print (G)
queue = list (); head = 0; tail = 1
queue.append (2); vis[2] = 1
while head < tail :
  u = queue[head]; head += 1
  for v, w in G[u] :
    if vis[v] == 0 :
      queue.append (v)
      vis[v] = 1
      tail += 1
res = 0
for i in range (2, n + 1) : res += vis[i] * ans[i]
print (res * 4)

    
