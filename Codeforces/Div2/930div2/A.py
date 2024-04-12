for _ in range (int (input ())) :
  n = int (input ())
  ans = 1
  while ans <= n :
    ans *= 2
  print (ans // 2)