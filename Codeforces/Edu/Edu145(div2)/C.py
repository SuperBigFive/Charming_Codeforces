for t in range (int (input ())) :
  n, k = map (int, input ().split ()); rev = 0
  if k == 0 :
    for i in range (n) : print (-1, end = " ")
    print ()
    continue
  elif k == (n + 1) * n // 2 :
    for i in range (n) : print (1, end = " ")
    print ()
    continue
  k = (n + 1) * n // 2 - k
  if k > (n + 1) * n // 2 - k : k = (n + 1) * n // 2 - k; rev = 1
  #print (k, rev)
  a = [1] * (n + 5)
  for i in range (n, 0, -1) :
    if k > i : a[i] = -1000; k -= i
    else : a[i - k] += 1; a[i] = -k; break
    #print (i, a[i])
  for i in range (1, n + 1) :
    if rev : print (-1 * a[i], end = " ")
    else : print (a[i], end = " ")
  print ()
