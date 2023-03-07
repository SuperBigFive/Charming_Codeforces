for t in range (int (input ())) :
  n = int (input ())
  if n & 1 == 0 :
    print (0)
    continue
  last = 0
  ok = False
  while n > 0 :
    last = n % 10
    if last & 1 == 0 :
      ok = True
    n //= 10
  if last & 1 == 0 :
    print (1)
    continue
  elif ok == True :
    print (2)
    continue
  else :
    print (-1)
      
