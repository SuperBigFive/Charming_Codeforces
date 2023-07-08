for t in range (int (input ())) :
  n, q = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  a.sort (reverse = True)
  tag = [0] * (n + 5)
  for i in range (q) :
    l, r = map (int, input ().split ())
    tag[l] += 1; tag[r + 1] -= 1;
  b = list ([0, 0] for i in range (n + 5))
  cur = 0; ans = 0
  for i in range (1, n + 1) :
    cur += tag[i]
    b[i][0] = cur + 1
    b[i][1] = i - 1
  b.sort (key = lambda x : x[0], reverse = True)
  c = [0] * (n + 5)
  for i in range (n) :
    ans += (b[i][0] - 1) * a[i]
    c[b[i][1]] = a[i]
  print (ans)
  for i in range (n) : print (c[i], end = " ")
  print ()
