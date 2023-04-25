for t in range (int (input ())) :
  n = int (input ())
  a = map (int, input ().split ())
  b = 0
  for i in a : b ^= i
  if n & 1 : print (b)
  elif b == 0 : print (0)
  else : print (-1)
