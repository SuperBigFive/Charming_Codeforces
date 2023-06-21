for t in range (int (input ())) :
  n = int (input ())
  ans = 0
  while n :
    ans += n
    n //= 2
  print (ans)
