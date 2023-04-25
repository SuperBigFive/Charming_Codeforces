for t in range (int (input ())) :
  a, b = map (int, input ().split ())
  ans = a + b
  for i in range (1, 5 * 10 ** 4 + 1) :
    nans = i - 1
    if a % i == 0 : nans += a // i
    else : nans += a // i + 1
    if b % i == 0 : nans += b // i
    else : nans += b // i + 1
    ans = min (ans, nans)
  print (ans)
  
