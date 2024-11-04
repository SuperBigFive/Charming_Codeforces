n, k = map (int, input ().split ())
vis = set (list (map (int, input ().split ())))
ans = k * (k + 1) // 2
for x in vis :
  if x <= k : ans -= x
print (ans)