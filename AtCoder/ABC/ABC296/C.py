n, x = map (int, input ().split ())
a = list (map (int, input ().split ()))
if x < 0 :
  x = -x
  for i in range (n) : a[i] = -a[i]
a.sort (); p = 0; ok = False
for i in range (n) :
  while p + 1 < n and a[p + 1] - a[i] <= x : p += 1
  if a[p] - a[i] == x : ok = True

print ("Yes" if ok else "No")
