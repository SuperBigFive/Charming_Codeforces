for t in range (int (input ())) :
  n = int (input ())
  p = list (map (int, input ().split ()))
  fast = n + 1; ans = 0
  for i in range (n - 1, -1, -1) :
    if p[i] < fast : ans += 1
    fast = min (fast, p[i])
  print (ans)
