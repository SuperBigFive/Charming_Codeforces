for t in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  b = list (map (int, input ().split ()))
  ok = True
  for i in range (n - 1) :
    if (a[i] <= a[-1] and b[i] <= b[-1]) or\
       (b[i] <= a[-1] and a[i] <= b[-1]) : continue
    else : ok = False; break
  print ("YES" if ok else "NO")
