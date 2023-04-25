import sys
sys.setrecursionlimit (200000)
for t in range (int (input ())) :
  n = int (input ())
  b = [0] + list (map (int, input ().split ()))
  p = [0] + list (map (int, input ().split ()))
  pos = [0] * (n + 1)
  root = int ()
  adj = list ()
  for i in range (n + 1) :
    adj.append ([])
  for i in range (1, n + 1) :
    if i == b[i] :
      root = i
    else :
      adj[b[i]].append (i)
    pos[p[i]] = i
    
  def dfs (f, u) :
    if pos[u] < pos[f] :
      return False
    for v in adj[u] :
      if dfs (u, v) == False :
        return False
    return True

  if dfs (root, root) == False :
    print (-1)
    continue
  sum = [0] * (n + 1)
  res = [0] * (n + 1)
  last = 0
  for i in range (1, n + 1) :
    if p[i] == root :
      continue
    res[p[i]] = last - sum[b[p[i]]] + 1
    sum[p[i]] = sum[b[p[i]]] + res[p[i]]
    last = sum[p[i]]
  for i in range (1, n + 1) :
    print (res[i], end = " ")
  print ("")
