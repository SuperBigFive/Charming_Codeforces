for _ in range (int (input ())) :
  k, q = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  n = list (map (int, input ().split ()))
  for ni in n :
    if ni < a[0] : print (ni, end = ' ')
    else : print (a[0] - 1, end = ' ')
  print ()
