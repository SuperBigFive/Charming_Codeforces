n, U = map (int, input ().split ())
E = list (map (int, input ().split ()))
p = 0; ans = -1
for i in range (n) :
  while p + 1 < n and E[p + 1] - E[i] <= U : p += 1
  if p > i + 1 : ans = max (ans, (E[p] - E[i + 1]) / (E[p] - E[i]))
print (ans)
