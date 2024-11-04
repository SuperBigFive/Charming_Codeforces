for _ in range (int (input ())) :
  n, k = map (int, input ().split ())
  if n == 1 :
    print (k)
    continue
  else :
    x, y = 0, 0
    while True :
      if k < x + (1 << y) : break
      x += 1 << y
      y += 1
    k -= x
    print (x, end = ' ')
    for i in range (n - 2) : print ('0', end = ' ')
    print (k)