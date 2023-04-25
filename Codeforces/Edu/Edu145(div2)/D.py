coin = int (1e12)
for t in range (int (input ())) :
  s = input (); n = len (s)
  s = '#' + s; sum0 = [0] * (n + 5); nxt = [0] * (n + 5)
  res = coin * n; cur = 0; last = 0
  for i in range (1, n + 1) :
    sum0[i] = sum0[i - 1]
    if s[i] == '0' : sum0[i] += 1
    elif last : nxt[last] = i; last = i
    else : last = i

  for i in range (1, n + 1) :
    if s[i] == '0' : continue
    elif nxt[i] == 0 : cur += min (coin + 1, (1 if n == i + 1 else n) * coin, (n - i) * (coin + 1)); break
    elif nxt[i] - i > 2 : cur += coin + 1
    elif nxt[i] - i == 2 : res = min (res, cur + (coin + 1) * \
                                         (sum0[n] - sum0[i]) - 1); cur += coin + 1
    else : res = min (res, cur + (coin + 1) * (sum0[n] - sum0[i])); cur += coin + 1
  print (min (res, cur))
