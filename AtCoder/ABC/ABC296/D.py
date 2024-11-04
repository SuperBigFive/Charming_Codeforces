n, m = map (int, input ().split ())
if n * n < m : print (-1); exit (0)
if n >= m : print (m); exit (0)
i = 1; res = 10 ** 18
while m // i > 1 and i <= n :
  j = max (i + 1, m // ((m // i) - 1))
  div = (m + i - 1) // i
  if div <= n : res = min (res, i * div)
  i = j
print (res)
