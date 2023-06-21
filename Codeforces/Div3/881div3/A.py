for t in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  a.sort ()
  ans = 0
  for i in range (n // 2) : ans += a[n - i - 1] - a[i]
  print (ans)
