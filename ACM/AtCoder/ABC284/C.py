import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, m = map (int, input ().split ())
  pre = list (i for i in range (n + 1))
  
  def find (u) :
    if u == pre[u] : return u
    pre[u] = find (pre[u])
    return pre[u]

  for i in range (m) :
    u, v = map (int, input ().split ())
    fu = find (u); fv = find (v)
    if fu == fv : continue
    pre[fu] = fv
  res = 0
  for i in range (1, n + 1) :
    if i == pre[i] : res += 1
  print (res)

charming ()
