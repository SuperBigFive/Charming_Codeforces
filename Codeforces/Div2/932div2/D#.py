for _ in range (int (input ())) :
  n, c = map (int, input ().split ())
  s = list (map (int, input ().split ()))
  ans = (c + 2) * (c + 1) // 2
  even_s, odd_s = [], []
  for x in s :
    ans -= x // 2 + 1
    if x & 1 : odd_s.append (x)
    else : even_s.append (x)
  even_l, even_r = 0, len (even_s) - 1
  odd_l, odd_r = 0, len (odd_s) - 1
  # (0, 0), (2, 2), (3, 3)
  # print ('!', ans)
  for x in s :
    ans -= (c - x) + 1
    ql, qr = x, c + c - x  
    # (0, x), (1, x + 1), (2, x + 2)
    if not x & 1 :
      while even_r >= 0 and \
        even_s[even_r] > qr : even_r -= 1
      while even_l < len (even_s) and \
        even_s[even_l] < ql : even_l += 1
      if even_l <= even_r : ans += even_r - even_l + 1
    else :
      while odd_r >= 0 and \
        odd_s[odd_r] > qr : odd_r -= 1
      while odd_l < len (odd_s) and \
        odd_s[odd_l] < ql : odd_l += 1
      if odd_l <= odd_r : ans += odd_r - odd_l + 1
  print (ans)
  
  # print (odd_s)

