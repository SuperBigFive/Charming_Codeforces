for _ in range (int (input ())) :
  n, m, k = map (int, input ().split ())
  if m == 1 : print ('No')
  elif k < n - (n + m - 1) // m : print ('Yes')
  else : print ('No')