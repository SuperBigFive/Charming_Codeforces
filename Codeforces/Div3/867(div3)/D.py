seq = [0] * (15); vis = [0] * (15)

def dfs (u, lim) :
  if u > lim :
    b = set (); Sum = 0
    for i in range (1, lim + 1) :
      Sum += seq[i]
      b.add (Sum % n)
    if len (b) == n :
      for i in range (1, lim + 1) :
        print (seq[i], end = " ")
      print ()
    return
  for i in range (1, lim + 1) :
    if vis[i] : continue
    seq[u] = i; vis[i] = 1
    dfs (u + 1, lim)
    vis[i] = 0

for t in range (int (input ())) :
  n = int (input ())
  if n == 1 : print (1)
  elif n & 1 : print (-1)
  else :
    b = list ()
    for i in range (1, n // 2) :
      b.append (i)
      b.append (n - i)
    b.append (n // 2)
    Sum = 0
    print (n, end = " ")
    for i in b :
      a = (i - Sum + n) % n
      if a == 0 : a = n
      Sum += a
      print (a, end = " ")
    print ()
  #n = int (input ())
  #dfs (1, n)
  
