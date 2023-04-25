for r in range (int (input ())) :
  m = int (input ())
  pos = dict ()
  for i in range (1, m + 1) :
    cnt = int (input ())
    a = list (map (int, input ().split ()))
    for j in a :
      if j not in pos : pos[j] = [i]
      else : pos[j] += [i]
  HaveWiner = [0] * (m + 5); ok = True
  for i in pos.keys () :
    #print (i, pos[i][-1])
    HaveWiner[pos[i][-1]] = i
  p = list ()
  for i in range (1, m + 1) :
    if HaveWiner[i] == 0 : ok = False; break;
    p.append (HaveWiner[i])
  if ok == False : print (-1)
  else :
    for i in range (1, m + 1) :
      print (HaveWiner[i], end = " ")
    print ()
  
