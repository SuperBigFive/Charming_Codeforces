for t in range (int (input ())) :
  n, m = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  last = [-1] * (n + m + 5); have = [0] * (n + m + 5);
  for i in a : last[i] = 0
  for i in range (1, m + 1) :
    pv = list (map (int, input ().split ()))
    have[a[pv[0] - 1]] += i - last[a[pv[0] - 1]]
    last[a[pv[0] - 1]] = -1; last[pv[1]] = i
    a[pv[0] - 1] = pv[1]
  for i in range (n + m + 5) :
    if last[i] >= 0 : have[i] += m - last[i] + 1
  res = 0
  for i in range (n + m + 5) : res += have[i] * ((m + 1) - have[i]) + \
                                      (have[i] - 1) * have[i] // 2
  print (res)
    
