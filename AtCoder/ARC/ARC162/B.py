n = int (input ())
p = [0] + list (map (int, input ().split ()))
ans = list ()
for i in range (1, n - 1) :
  if p[i] != i :
    j = i
    while j <= n and p[j] != i : j += 1
    if j == n :
      ans.append ((n - 1, n - 3))
      ans.append ((n - 1, i - 1))
      p[n - 2], p[n - 1], p[n] = p[n - 1], p[n], p[n - 2]
      p = p[:i] + [p[n - 1], p[n]] + p[i: n - 1]
    else :
      ans.append ((j, i - 1))
      p = p[:i] + [p[j], p[j + 1]] + p[i : j] + p[j + 2 :]
if p[n] != n or p[n - 1] != n - 1: print ("No")
else :
  print ("Yes")
  print (len (ans))
  for i, j in ans : print (i, j)
