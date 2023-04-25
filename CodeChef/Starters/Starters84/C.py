for t in range (int (input ())) :
  n = int (input ()); a = list (map (int, input ().split ()))
  b = []; a.sort (); p1 = 0; p2 = n - 1
  while p1 < p2 :
    b.append (a[p1]); p1 += 1
    b.append (a[p2]); p2 -= 1
  if p1 == p2 : b.append (a[p1])
  ok = True
  for i in range (n - 1) :
    if b[i] + b[i + 1] >= a[-1] + a[-2] : ok = False; break
  if ok : print ("YES"); continue
  b = []; p1 = 0; p2 = n - 1
  while p1 < p2 :
    b.append (a[p2]); p2 -= 1
    b.append (a[p1]); p1 += 1
  if p1 == p2 : b.append (a[p1])
  ok = True
  for i in range (n - 1) :
    if b[i] + b[i + 1] >= a[-1] + a[-2] : ok = False; break
  print ("YES" if ok else "NO")
