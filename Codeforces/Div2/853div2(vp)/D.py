import copy
for t in range (int (input ())) :
  n = int (input ())
  a = list (input ()); b = list (input ())
  for i in range (n) :
    if a[i] == '1' : a[i] = 1
    else : a[i] = 0
    if b[i] == '1' : b[i] = 1
    else : b[i] = 0
  fi_a = n + 5; fi_b = n + 5
  for i in range (n) :
    if a[i] == 1 and fi_a == n + 5 : fi_a = i
    if b[i] == 1 and fi_b == n + 5 : fi_b = i
  if fi_a >= n + 5 and fi_b < n + 5 : print (-1); continue
  if fi_a < n + 5 and fi_b >= n + 5 : print (-1); continue
  if fi_a >= n + 5 and fi_b >= n + 5 : print (0); continue
    
  def modify (n, k):
    c = copy.deepcopy (a)
    for i in range (n) :
      if i + k >= n or i + k < 0 : c[i] = a[i]
      else : c[i] = a[i] ^ a[i + k]
    return c

  ans = list (); be = n - 1
  while b[be] == 0 : be -= 1
  if a[be] != 1 :
    ans.append (-(be - fi_a))
    a = modify (n, -(be - fi_a))
  fi_a = min (fi_a, be)
  for i in range (be + 1, n) :
    if a[i] == b[i] : continue
    else :
      ans.append (fi_a - i)
      a = modify (n, fi_a - i)
  for i in range (be - 1, -1, -1) :
    if a[i] == b[i] : continue
    else :
      ans.append (be - i)
      a = modify (n, be - i)
  

  print (len (ans))
  for i in ans : print (i, end = " ")
  if len (ans) : print ()
