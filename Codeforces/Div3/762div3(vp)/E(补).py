for t in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  a = sorted (a)
  d = dict ()
  res = dict ()
  for i in range (n + 1)  :
    if i < n :
      if d.get (a[i], -1) == -1 : d[a[i]] = 1
      else : d[a[i]] = d[a[i]] + 1
    res[i] = -1
  flag = False
  last = 0
  stk = list ()
  if d.get (0, -1) == -1 :
    print (0, end = " ")
  else :
    print (d[0], end = " ")
    for i in range (d[0] - 1) :
      stk.append (0)
  for i in range (1, n + 1) :
    if (flag == True) :
      print (-1, end = " ")
      continue
    elif d.get (i - 1, -1) == -1 :
      if len (stk) <= 0 :
        flag = True
        print (-1, end = " ")
        continue
      last += i - 1 - stk[len (stk) - 1]
      stk.pop ()
    if d.get (i, -1) != -1:
      for j in range (d[i] - 1) :
        stk.append (i)
    if d.get (i, -1) == -1 : print (last, end = " ")
    else : print (last + d[i], end = " ")
  print ("\n")
        
