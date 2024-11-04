for _ in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  ans = 0
  cnt = {}
  for i in range (n) :
    chk = cnt.get (a[i], 0)
    if chk : ans += 1
    cnt[a[i]] = chk + 1
  print (ans)
    