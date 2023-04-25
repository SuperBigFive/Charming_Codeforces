for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  cnt_a = dict (); cnt_b = dict ()
  A = list (map (str, input ().split ()))
  B = list (map (str, input ().split ()))
  ok = True
  for i in range (n) :
    siz_a = len (A[i]); siz_b = len (B[i])
    if siz_a != siz_b : ok = False; break
    else :
      for j in range (siz_a) :
        cnt_a[A[i][j]] = cnt_a.get (A[i][j], 0) + 1
        cnt_b[B[i][j]] = cnt_b.get (B[i][j], 0) + 1
  if ok == False : print ("NO"); continue
  ch = ['0', '1', '2', '3', '4', '5','6', '7', '8', '9']
  cost = 0
  for i in ch :
    cnt_a[i] = cnt_a.get (i, 0)
    cnt_b[i] = cnt_b.get (i, 0)
    if cnt_a[i] > cnt_b[i] : cost += cnt_a[i] - cnt_b[i]
  print ("YES" if cost <= k else "NO")
