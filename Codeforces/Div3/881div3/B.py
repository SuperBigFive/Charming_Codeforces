for t in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  ans = 0; op = 0
  i = 0; j = 0
  for ai in a : ans += abs (ai)
  while i < n :
    j = i
    if a[i] < 0 :
      while j + 1 < n and a[j + 1] <= 0 : j += 1
      op += 1
    i = j + 1
  print (ans, op)
