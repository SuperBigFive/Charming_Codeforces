for t in range (int (input ())) :
  n, m = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  b = list (map (int, input ().split ()))
  mx = -1; id = -1
  for i in range (n) :
    if i + a[i] <= m :
      if b[i] > mx : mx = b[i]; id = i + 1
  print (id)
