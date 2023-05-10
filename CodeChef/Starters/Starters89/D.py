for t in range (int (input ())) :
  n, m, k = map (int, input ().split ())
  a = [0] + list (map (int, input ().split ()))
  b = [0] + list (map (int, input ().split ()))
  
  c = sum (a); d = sum (b)
  if k == 1: print (-1); continue
  elif c * m > d * n : print (0); continue
  l = 0; r = 10 ** 9; ans = r

  def Get_ans (n, m, c, d, k, y) -> int :
    if c * (m + y) > n * (d + y) : return y
    else :
      p = m * k + k * y - d - y
      q = n * d + n * y - c * y - c * m
      if p == 0 : return 10 ** 9
      else : return q // p + 1 + y

  while l <= r - 10:
    mid1 = l + (r - l) // 3; mid2 = r - (r - l) // 3
    ans1 = Get_ans (n, m, c, d, k, mid1)
    ans2 = Get_ans (n, m, c, d, k, mid2)
    if ans1 < ans2 : r = mid2 - 1; ans = ans1
    else : l = mid1 + 1; ans = ans2
  for i in range (l, r + 1) : ans = min (ans, Get_ans (n, m, c,d, k, i))
  print (ans)
    
