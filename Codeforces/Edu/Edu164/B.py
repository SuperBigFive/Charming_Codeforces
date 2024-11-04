for _ in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  now, cnt = 0, 0
  ans = 10 ** 18
  while now < n :
    nxt = now + 1
    while nxt < n and a[nxt] == a[0] : nxt += 1
    ans = min (ans, nxt - now)
    cnt += 1
    now = nxt + 1
  if cnt == 1 : ans = -1
  print (ans)