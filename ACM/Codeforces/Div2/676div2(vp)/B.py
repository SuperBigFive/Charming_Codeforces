for t in range (int (input ())) :
  n = int (input()); s = list ()
  for i in range (n) :
    s.append (list (input ()))
  ans = list ()
  if s[n - 1][n - 2] == s[n - 2][n - 1] :
    if s[0][1] == s[n - 1][n - 2] : ans.append ([1, 2])
    if s[1][0] == s[n - 1][n - 2] : ans.append ([2, 1])
  elif s[0][1] == s[1][0] :
    if s[n - 1][n - 2] == s[0][1] : ans.append ([n, n - 1])
    if s[n - 2][n - 1] == s[0][1] : ans.append ([n - 1, n])
  else :
    if s[0][1] == '0' : ans.append ([1, 2])
    else : ans.append ([2, 1])
    if s[n - 2][n - 1] == '1' : ans.append ([n - 1, n])
    else : ans.append ([n, n - 1])
  print (len (ans))
  for i, j in ans : print (i, j)
