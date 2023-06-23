n, k1, k2 = map (int, input ().split ())
a = list (map (int, input ().split ()))
b = list (map (int, input ().split ()))
c = list ()
for i in range (n) : c.append (abs (a[i] - b[i]))
c.sort (reverse = True)
for i in range (k1 + k2) :
  if c[0] <= 0 : c[0] += 1
  else : c[0] -= 1
  i = 1
  while i < n and c[i] > c[0] : i += 1
  if i == 1 : continue
  else : c = c[1 : i] + [c[0]] + c[i :]
ans = 0
for i in c : ans = (ans + i * i)
print (ans)
  
