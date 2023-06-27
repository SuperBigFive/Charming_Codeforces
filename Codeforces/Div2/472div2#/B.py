n, m = map (int, input ().split ()); mp = list ()
for i in range (n) : mp.append (input ())
for c in range (m) :
  a = list ()
  for r in range (n) :
    if mp[r][c] == '#' : a.append (r)
  if len (a) == 0 : continue
  for i in a :
    if mp[i] != mp[a[0]] : print ("No"); exit (0)
print ("Yes")
