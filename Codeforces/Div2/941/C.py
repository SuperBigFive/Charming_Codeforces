for _ in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  a.sort ()
  b = list (set (a))
  m = len (b)
  c = []
  for i in range (m) :
    delta = b[i] - (b[i - 1] if i - 1 >= 0 else 0)
    c.append (delta)
  win = 0
  for i in range (m - 2, -1, -1) :
    if c[i] == 1 :
      win ^= 1
    elif win == 1 : win = 0
  if win == 0 : print ('Alice')
  else : print ('Bob')