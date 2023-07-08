for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  cnt0, cnt1 = n // 2, (n + 1) // 2
  if cnt1 < k : print ("NO")
  else :
    delta = cnt1 - k
    if delta & 1 : print ("NO")
    else :
      delta //= 2; cnt0 += delta
      if cnt0 >= k : print ("YES")
      else : print ("NO")
