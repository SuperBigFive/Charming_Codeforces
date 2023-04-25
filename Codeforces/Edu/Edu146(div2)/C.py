for t in range (int (input ())) :
  n, s1, s2 = map (int, input ().split ())
  r = list (map (int, input ().split ()))
  for i in range (n) :
    r[i] = [r[i], i + 1]
  r.sort (key = lambda x : x[0], reverse = True)
  rev = False
  if s1 < s2 : s1, s2 = s2, s1; rev = True
  ans_a = []; ans_b = []
  cost_a = []; cost_b = []
  for i in range (n) :
    cost_a.append ((i + 1) * s1)
    cost_b.append ((i + 1) * s2)
  pa = 0; pb = 0
  for i in range (n) :
    if cost_a[pa] < cost_b[pb] : pa += 1; ans_a.append (r[i][1])
    else : pb += 1; ans_b.append (r[i][1])
  if rev : ans_a, ans_b = ans_b, ans_a
  print (len (ans_a), end = " ")
  for i in ans_a : print (i, end = " ")
  print ("\n" + str (len (ans_b)), end = " ")
  for i in ans_b : print (i, end = " ")
  print ()
