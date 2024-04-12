for _ in range (int (input ())) :
  n, k = map (int, input ().split ())
  G = [[] for i in range (n + 1)]
  du = [0] * (n + 1)
  ndu = [0] * (n + 1)
  vis = [0] * (n + 1)
  siz = [0] * (n + 1)
  for i in range (n - 1) :
    u, v = map (int, input ().split ())
    G[u].append (v)
    G[v].append (u)
    du[u] += 1
    du[v] += 1

  def Check (mid) :
    q = []
    for i in range (1, n + 1) :
      ndu[i] = du[i]
      vis[i] = 0; siz[i] = 1
      if du[i] == 1 and i != 1 :
        q.append (i)
    val = []
    for i in range (n - 1) :
      u = q[i]
      vis[u] = 1
      for v in G[u] :
        if vis[v] : continue
        else : 
          ndu[v] -= 1
          if ndu[v] == 1 and v != 1 :
            q.append (v)
          if siz[u] >= mid : val.append (siz[u])
          else : siz[v] += siz[u]
    val.sort ()
    remain, num = n, 0
    for x in val :
      if remain - x < mid : break
      else :
        remain -= x
        num += 1
    return num >= k

  l, r, ans = 1, n, 1
  while l <= r :
    mid = (l + r) >> 1
    if Check (mid) : l = mid + 1; ans = mid
    else : r = mid - 1
  print (ans)