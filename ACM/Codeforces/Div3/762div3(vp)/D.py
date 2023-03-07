for t in range (int (input ())) :
  s = input ();
  m, n = map (int, input ().split ())
  p = list ()
  for i in range (m) :
    p.append (list (map (int, input ().split ())))
  l = 1
  r = 1e9
  res = 1
  while l <= r :
    mid = (l + r) // 2
    d = dict ()
    ok1 = False
    for i in range (n) :
      ok2 = False
      for j in range (m) :
        if p[j][i] < mid : continue;
        ok2 = True
        if d.get (j, -1) != -1 :
          ok1 = True;
          break
        d[j] = 1
      if ok2 == False :
        ok1 = False
        break
    if ok1 == True :
      l = mid + 1
      res = mid
    else : r = mid - 1
  print (int (res))
