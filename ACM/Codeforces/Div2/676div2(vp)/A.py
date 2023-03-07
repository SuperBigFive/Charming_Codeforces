for t in range (int (input ())) :
  a, b = map (int, input ().split ())
  res = 0
  for i in range (30) :
    ok1 = (a >> i) & 1; ok2 = (b >> i) & 1
    if ok1 == 0 and ok2 == 0 : continue
    elif ok1 == 1 and ok2 == 1 : continue
    else : res += (1 << i)
  print (res)
