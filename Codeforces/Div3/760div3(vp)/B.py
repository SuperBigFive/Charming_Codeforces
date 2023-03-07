for t in range (int (input ())) :
  n = int (input ())
  s = list (map (str, input ().split ()))
  res = list ()
  res.append (s[0][0])
  res.append (s[0][1])
  id = -1
  for i in range (1, n - 2) :
    if s[i][0] != s[i - 1][1] :
      id = i
      break
  for i in range (1, n - 2) :
    if i == id : res.append (s[i][0])
    res.append (s[i][1])
  if id == -1 : res.append ("a")
  for i in res :
    print (i, end = "")
  print ("")
