N = 2 * (10 ** 5) + 5
n, m ,q = map (int, input ().split ())
edge = []; query = []
for i in range (m) :
  u, v, w = map (int, input ().split ())
  edge.append ((u, v, w))
edge.sort (key = lambda x : x[2])
for i in range (q) :
  d, k = map (int, input ().split ())
  query.append ((d, k, i))
query.sort (key = lambda x : x[1])

node = [0] * N

def lowbit (x) : return x & -x

def Modify (x, k) :
  while x < N : node[x] += k; x += lowbit (x)
  return

def Query (x) :
  res = 0
  while x : res += node[x]; x -= lowbit (x)
  return res
    
pe = 0; pk = 0; siz = [0] * (n + 5); ans = [0] * (q + 5)
Modify (1, n)
while pk < q :
  npk = pk
  while npk < q and query[npk][1] == query[pk][1] : npk += 1
  while pe < m and edge[pe][2] <= query[pk][1] :
    u = edge[pe][0]; v = edge[pe][1]
    if siz[u] > 0 :
      Modify (siz[u], -1)
      Modify (siz[u] + 1, 1)
    if siz[v] > 0 :
      Modify (siz[v], -1)
      Modify (siz[v] + 1, 1)
    siz[u] += 1; siz[v] += 1
    pe += 1
  for i in range (pk, npk) : ans[query[i][2]] = Query (query[i][0])
  pk = npk
for i in range (q) : print (ans[i])
  
