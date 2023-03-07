for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  inv_a = (n - k) * (n - k + 1) // 2
  stk = list (range (2 * k - n, k + 1)); p = [0] * (n + 5)
  for i in range (1, k - (n - k)) : p[i] = i
  for i in range (k - (n - k), k + 1) : p[i] = stk.pop ()
  for i in range (1, k + 1) : print (p[i], end = " ")
  print ()
  
