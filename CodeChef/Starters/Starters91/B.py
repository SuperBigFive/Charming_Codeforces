for t in range (int (input ())) :
  n = int (input ())
  if n & 1 :
    if n > 1 : print (-1)
    else : print (1)
  else :
    for i in range (n, 0, -1) : print (i, end = " ")
    print ()
