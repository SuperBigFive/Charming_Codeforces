for t in range (int (input ())) :
  n = int (input ())
  G = list (list () for i in range (n))
  du = [0] * n; du[0] = 1
  for i in range (n - 1) :
    u, v = map (int, input ().split ())
    u -= 1; v -= 1
    G[u].append (v)
    G[v].append (u)
    du[u] += 1; du[v] += 1
  siz = [0] * n

  queue = list (); head = 0; tail = 0
  for i in range (1, n) :
    if len (G[i]) == 1 :
      siz[i] = 1
      queue.append (i)
      tail += 1
  while head < tail :
    u = queue[head]; head += 1
    for v in G[u] :
      if du[v] <= 1 : continue
      siz[v] += siz[u]
      du[v] -= 1
      if du[v] <= 1 :
        queue.append (v)
        tail += 1
      
  q = int (input ())
  for i in range (q) :
    x, y = map (int, input ().split ())
    x -= 1; y -= 1
    print (siz[x] * siz[y])
