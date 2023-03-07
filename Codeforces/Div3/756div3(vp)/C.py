for t in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  if a[0] != n and a[n - 1] != n :
    print (-1)
    continue
  elif a[0] == n :
    a = list (reversed (a[1 : n])) + [n]
  else :
    a = list (reversed (a[0 : n - 1])) + [n]
  for i in a :
    print (i, end = " ")
  print ("")
