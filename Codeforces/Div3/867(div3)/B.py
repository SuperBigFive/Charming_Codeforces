for i in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  pos = list (); neg = list ()
  for i in a :
    if i >= 0 : pos.append (i)
    else : neg.append (i)
  pos.sort (); neg.sort ()
  mx = -10 ** 18
  if len (pos) > 1 : mx = max (mx, pos[-1] * pos[-2])
  if len (neg) > 1 : mx = max (mx, neg[0] * neg[1])
  if len (pos) and len (neg) : mx = max (mx, pos[0] * neg[-1])
  print (mx)
