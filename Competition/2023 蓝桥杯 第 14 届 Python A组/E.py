for t in range (int (input ())) :
  s1 = list (input ()); s2 = list (input ()); n = len (s1)
  p = 0; ok = True; seq = []
  if s1[0] != s2[0] or s1[-1] != s2[-1] : print (-1); continue
  while p < n :
    q = p
    if p >= n - 1 : break
    if s2[p + 1] == s2[p] :
      while q < n  and s2[q] == s2[p] : q += 1
      if q > p + 1 :
        for i in range (p, q) :
          if s1[i] != s2[i] : ok = False; break
        if ok == False : break
    else :
      while q < n  and (((q - p) & 1 and s2[q] != s2[p]) \
            or ((q - p) == 0 and s2[q] == s2[p])) : q += 1
      seq.append ((p, q - 1))
    p = q
  if ok == False : print (-1); continue
  ans = 0
  for l, r in seq :
    if l == 1 : l += 1
    if r == n - 1 : r -= 1
    for i in range (l, r + 1) :
      if s2[i] != s1[i] :
        if s2[i] != s2[i - 1] and s2[i] != s2[i + 1] :
          s2[i] = s1[i]; ans += 1
        else : break
  print (ans if ok else -1)
