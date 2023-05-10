for t in range (int (input ())) :
  n = int (input ())
  b = list (map (int, input ().split ()))
  p, q = 0, 0
  for i in range (n) :
    if b[i] == 1 : p += i + 1
    else : q += i + 1
  print (abs (p - q))
