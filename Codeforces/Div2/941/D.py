for _ in range (int (input ())) :
  n, k = map (int, input ().split ())
  ans = []
  if k == 1 :
    for i in range (1, 20) :
      ans.append (1 << i)
    ans.append (3)
  else :
    now = 1
    high = 1; cnt = 0
    while high * 2 <= k - 1:
      high <<= 1
      cnt += 1
    for i in range (cnt) :
      ans.append (1 << i)
    ans.append (k - high)
    ans.append (k + 1)
    ans.append (k + 1)
    ans.append (2 * k + 1)
    mx = 3 * k
    while True :
      nxt = mx - k
      if nxt > n : break
      ans.append (nxt)
      mx += nxt
  m = len (ans)
  print (m)
  for i in range (m) :
    print (ans[i], end = ' ' if i < m - 1 else '\n')
