for t in range (int (input ())) :
  s = input (); color = dict ()
  for i in s :
    if i in color : color[i] += 1
    else : color[i] = 1
  cnt = list ()
  for i in color : cnt.append (color[i])
  if len (cnt) >= 3 : print (4)
  elif len (cnt) == 1 : print (-1)
  elif cnt[0] == 2 : print (4)
  else : print (6)
