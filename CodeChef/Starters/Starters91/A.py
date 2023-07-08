for t in range (int (input ())) :
  n = int (input ()); s = input ()
  ans1, ans2 = 0, 0
  cur = 0
  for ch in s :
    if ch == 'A' and cur == 0 : ans1 += 1
    elif ch == 'A' and cur == 1 : cur = 0
    elif ch == 'B' and cur == 0 : cur = 1
    else : ans2 += 1
  print (ans1, ans2)
