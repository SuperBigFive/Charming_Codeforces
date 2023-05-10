for t in range (int (input ())) :
  n = int (input ())
  a = [0] + list (map (int, input ().split ()))
  pos = [0] * (n + 5)
  mx = [0] * (n + 5); mn = [n] * (n + 5)
  for i in range (1, n + 1) : pos[a[i]] = i
  for i in range (n, 1, -1) :
    mx[i] = max (mx[i + 1], pos[i])
    mn[i] = min (mn[i + 1], pos[i])
    #print (i, mx[i], mn[i])
    if mx[i] - mn[i] == n - i : ans = n - i + 1
  print (ans)

