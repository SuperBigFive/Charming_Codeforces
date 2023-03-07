for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  a = ['#']+ list (input ()); b = ['#'] + list (input ());
  cnt1 = dict (); cnt2 = dict ();
  ch = "abcdefghijklmnopqrstuvwxyz"; ok = True;
  for i in ch : cnt1[i] = cnt2[i] = 0
  k = min (k, n)
  if n - k + 1 <= k :
    for i in range (n - k + 1, k + 1) :
      if a[i] != b[i] : ok = False; break
  if ok == 0 : print ("NO"); continue
  for i in range (1, n + 1) :
    if i >= n - k + 1 and i <= k : continue
    cnt1[a[i]] += 1; cnt2[b[i]] += 1
  for i in ch :
    if cnt1[i] != cnt2[i] : ok = False; break
  print ("YES" if ok else "NO")
