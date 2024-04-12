for _ in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  a.sort ()
  cnt = 1
  for i in range ((n + 1) // 2, n) :
    if a[i] != a[i - 1] : break
    cnt += 1
  print (cnt)
