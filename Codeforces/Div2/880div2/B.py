for t in range (int (input ())) :
  n, k, g = map (int, input ().split ())
  add = (g - 1) // 2
  if add == 0 : print (0); continue
  d = min (n - 1, k * g // add)
  ans = add * d
  r = (k * g - (add * d)) % g
  if r >= (g + 1) // 2 : ans -= (g - r)
  else : ans += r
  print (max (0, ans))
    
