for t in range (int (input ())) :
  n, d = map (int ,input ().split ())
  a = list (map (int, input ().split ()))
  a.sort ()
  if a[0] + a[1] < 0 : print ("YES")
  elif a[n - 1] <= d : print ("YES")
  elif a[0] + a[1] <= d : print ("YES")
  else : print ("NO")
