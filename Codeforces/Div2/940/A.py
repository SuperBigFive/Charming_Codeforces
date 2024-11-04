N = 105

for _ in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  cnt = dict ()
  for x in a :
    cnt[x] = cnt.get (x, 0) + 1
  ans = 0
  for i in range (1, 105) :
    ans += cnt.get (i, 0) // 3
  print (ans)