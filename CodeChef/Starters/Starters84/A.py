for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  s = list (input ())
  if s[0] != '1' : s[0] = '1'; k -= 1
  for i in s : print (i, end = "")
  for i in range (k) : print (0, end = "")
  print ()
