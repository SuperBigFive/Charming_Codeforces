for t in range (int (input ())) :
  n = int (input ())
  if n == 1 : print (0); continue
  elif n <= 4 : print (1); continue
  elif n <= 9 : print (2); continue
  l = 3; r = 10000000000; res = 3
  while l <= r :
    mid = (l + r) // 2
    if (((mid & 1) and ((mid + 1) * (mid // 2 + 1) // 2 * 4 < n)) \
        or ((not(mid & 1)) and ((mid + 2) * mid // 2 // 2) * 4 + 1 < n)) : l = mid + 1
    else : r = mid - 1; res = mid
  print (res)
