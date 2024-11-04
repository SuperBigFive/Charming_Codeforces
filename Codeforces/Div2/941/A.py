for _ in range (int (input ())) :
  n, k = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  cnt = dict ()
  chk = False
  for x in a :
    cnt[x] = cnt.get (x, 0) + 1
    if cnt[x] >= k : chk = True
  if not chk : print (n)
  else : print (k - 1)