import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, m = map (int, input ().split ());
  pre = [0] * (n + 5); du = [0] * (n + 5); siz = [1] * (n + 5)
  for i in range (1, n + 1) : pre[i] = i

  def find (x) -> int:
    if x == pre[x] : return x
    pre[x] = find (pre[x])
    return pre[x]

  edge = list ()
  for i in range (m) :
    u, v = map (int, input ().split ())
    edge.append ((u, v))
    du[u] += 1; du[v] += 1
  for u, v in edge :
    fu = find (u); fv = find (v)
    if fu != fv :
      pre[fu] = fv
      du[fv] += du[fu]
      siz[fv] += siz[fu]
  res = 0
  for i in range (1, n + 1) :
    if i == pre[i] :
      res += max (0, (du[i] // 2) - siz[i] + 1)
  print (res)
    
charming ()
