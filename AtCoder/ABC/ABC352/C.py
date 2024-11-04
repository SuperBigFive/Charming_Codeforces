n = int (input ())
a, b = [], []
sum_a = 0
for i in range (n) :
  ai, bi = map (int, input ().split ())
  a.append (ai); b.append (bi)
  sum_a += ai
ans = 0
for i in range (n) :
  ans = max (ans, sum_a - a[i] + b[i])
print (ans)