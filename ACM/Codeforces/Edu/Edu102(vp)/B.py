for t in range (int (input ())) :
  s1 = input (); s2 = input (); ns = s1
  n = len (s1); m = len (s2); ok = False
  for i in range (20):
    nlen = len (ns)
    if nlen % m : ns += s1; continue
    chk = True; j = 0
    while j < nlen :
      if ns[j : j + m] != s2 :
        chk = False
        break
      else : j += m
    if chk : print (ns); ok = True; break
    ns += s1
  if ok == False : print (-1)
