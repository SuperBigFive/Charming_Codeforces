import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = [0] + list (map (int, input ().split ()))
  b = [0] * (n + 5); vis = [0] * (n + 5)
  for i in range (1, n + 1) :
    if a[i] != a[i - 1] : b[i] = a[i]; vis[b[i]] = 1
  c = [0] * (n + 5); i = 2; c[1] = b[1]
  pre = [0] * (n + 5); nxt = [0] * (n + 5)
  for i in range (1, n + 1) :
    pre[i] = i - 1
    nxt[i] = i + 1
  used = [0] * (n + 5)
  i = 2; used[c[1]] = 1; p = 1
  while i <= n :
    while b[i] :
      c[i] = b[i]; used[c[i]] = 1
      pre[nxt[c[i]]] = pre[c[i]]
      nxt[pre[c[i]]] = nxt[c[i]]
      i += 1
    if i > n : break
    j = i;
    while j + 1 <= n and b[j + 1] == 0 : j += 1
    for k in range (i, j + 1) :
      while used[p] == 1 : p = nxt[p]
      c[k] = p; used[p] = 1
      pre[nxt[p]] = pre[p]
      nxt[pre[p]] = nxt[p]
    i = j + 1;
  for i in range (1, n + 1) : print (c[i], end = " ")
  print ()
  for i in range (1, n + 1) :
    pre[i] = i - 1
    nxt[i] = i + 1
  used = [0] * (n + 1)
  i = 2; used[c[1]] = 1
  while i <= n :
    while b[i] :
      c[i] = b[i]; used[c[i]] = 1
      pre[nxt[c[i]]] = pre[c[i]]
      nxt[pre[c[i]]] = nxt[c[i]]
      i += 1
    if i > n : break
    j = i;
    while j + 1 <= n and b[j + 1] == 0 : j += 1
    p = a[j]
    for k in range (i, j + 1) :
      while used[p] : p = pre[p]
      c[k] = p; used[p] = 1
      pre[nxt[p]] = pre[p]
      nxt[pre[p]] = nxt[p]
    i = j + 1;
  for i in range (1, n + 1) : print (c[i], end = " ")
  print ()
  
for t in range (int (input ())) : charming ()
