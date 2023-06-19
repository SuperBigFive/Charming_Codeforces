for t in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  cnt = dict ()
  for i in a : cnt[i] = cnt.get (i, 0) + 1
  ok = True
  for i in range (1, 100) :
    if cnt.get (i, 0) > cnt.get (i - 1, 0) : ok = False
  if ok : print ("YES")
  else : print ("NO")
