n = int (input ()); dp0, dp1 = 0, -10 ** 18
for i in range (n) :
  x, y = map (int, input ().split ())
  ndp0 = dp0; ndp1 = dp1
  if x == 0 : ndp0 = max (ndp0, dp0 + y, dp1 + y)
  else : ndp1 = max (ndp1, dp0 + y)
  dp0 = max (dp0, ndp0); dp1 = max (dp1, ndp1)
print (max (dp0, dp1))
