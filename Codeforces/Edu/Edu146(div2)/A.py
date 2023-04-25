for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  if n & 1 :
    if k & 1 : print ("YES")
    else : print ("NO")
  else : print ("YES")
