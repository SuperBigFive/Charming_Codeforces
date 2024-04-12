for _ in range (int (input ())) :
  n, m = map (int, input ().split ())
  if (n ^ m) < n :
    print (1)
    print (n, m)
  else :
    ans = [n]
    p = 1; cnt = 0
    while (p << 1) <= n : p <<= 1; cnt += 1
    y = p
    flag = False
    for i in range (cnt - 1, -1, -1) :
      if (n >> i) & 1 :
        flag = True
      elif flag :
        y += (1 << i)
    n ^= y
    ans.append (n)
    if n < m :
      print (-1)
      continue
    for i in range (63, -1, -1) :
      if (n >> i) & 1 and not (m >> i) & 1 :
        n -= (1 << i)
        ans.append (n)
    print (len (ans) - 1)
    for x in ans :
      print (x, end = ' ' if x != ans[-1] else '\n')
    