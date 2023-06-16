n = int (input ())
a = list (map (int, input ().split ()))
ans, cur = 0, 0
for i in range (n) :
  if a[i] == i + 1 : ans = max (ans, i)
  if a[i] == 1000 - (n - i - 1) : ans = max (ans, n - i - 1)
for i in range (1, n - 1) :
  for j in range (i, n - 1) :
    if a[j + 1] == a[i - 1] + j - i + 2 : ans = max (ans, j - i + 1)
print (ans)
